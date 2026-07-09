import React, { useEffect, useRef, useState } from 'react'
import * as THREE from 'three'

function App() {
  const containerRef = useRef<HTMLDivElement>(null)
  const [showText, setShowText] = useState(false)

  useEffect(() => {
    const timer = setTimeout(() => setShowText(true), 300)
    return () => clearTimeout(timer)
  }, [])

  useEffect(() => {
    if (!containerRef.current) return

    const badge = containerRef.current
    
    const renderer = new THREE.WebGLRenderer({ antialias: true, alpha: true })
    renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))
    badge.appendChild(renderer.domElement)
    renderer.domElement.style.position = 'absolute'
    renderer.domElement.style.inset = '0'
    renderer.domElement.style.borderRadius = '50%'

    const scene = new THREE.Scene()
    const camera = new THREE.PerspectiveCamera(38, 1, 0.1, 100)
    camera.position.set(0, 0.1, 6.2)
    camera.lookAt(0, 0, 0)

    function resize() {
      const size = badge.clientWidth
      renderer.setSize(size, size, false)
      camera.aspect = 1
      camera.updateProjectionMatrix()
    }
    window.addEventListener('resize', resize)
    resize()

    // --- corporate, cool-toned studio lighting: obsidian / slate / ice blue / platinum ---
    scene.add(new THREE.AmbientLight(0x262a32, 0.5))

    const key = new THREE.DirectionalLight(0xffffff, 1.9)
    key.position.set(-4, 5, 4)
    scene.add(key)

    const rim = new THREE.DirectionalLight(0x8fc5ff, 1.15)
    rim.position.set(4, -1, -3)
    scene.add(rim)

    const fillLight = new THREE.PointLight(0x5b6572, 1.0, 20)
    fillLight.position.set(0, -3, 3)
    scene.add(fillLight)

    const sweep = new THREE.PointLight(0xbfe0ff, 2.6, 10, 2)
    sweep.position.set(3, 2, 3)
    scene.add(sweep)

    // --- faceted low-poly sphere (icosahedron), obsidian -> slate -> ice/platinum gradient ---
    const RADIUS = 1.7
    const baseGeo = new THREE.IcosahedronGeometry(RADIUS, 1)
    const nonIndexed = baseGeo.index ? baseGeo.toNonIndexed() : baseGeo
    const pos = nonIndexed.attributes.position

    const colorRaw   = new THREE.Color(0x08090b) // obsidian black — unmanaged spend
    const colorSlate = new THREE.Color(0x5b6572) // slate grey — current state
    const colorIce   = new THREE.Color(0x9fd0ff) // ice blue — optimization
    const colorValue = new THREE.Color(0xf3f6fa) // platinum white — realized value

    function gradientColor(t: number) {
      if (t < 0.45) {
        return colorRaw.clone().lerp(colorSlate, THREE.MathUtils.smoothstep(t, 0, 0.45))
      } else if (t < 0.8) {
        return colorSlate.clone().lerp(colorIce, THREE.MathUtils.smoothstep(t, 0.45, 0.8))
      } else {
        return colorIce.clone().lerp(colorValue, THREE.MathUtils.smoothstep(t, 0.8, 1))
      }
    }

    const group = new THREE.Group()
    scene.add(group)

    const faceCount = pos.count / 3
    const faces: Array<{ mesh: THREE.Mesh, material: THREE.MeshPhysicalMaterial, targetPos: THREE.Vector3, startPos: THREE.Vector3, delay: number }> = []

    for (let f = 0; f < faceCount; f++) {
      const i0 = f * 3, i1 = f * 3 + 1, i2 = f * 3 + 2
      const v0 = new THREE.Vector3().fromBufferAttribute(pos as THREE.BufferAttribute, i0)
      const v1 = new THREE.Vector3().fromBufferAttribute(pos as THREE.BufferAttribute, i1)
      const v2 = new THREE.Vector3().fromBufferAttribute(pos as THREE.BufferAttribute, i2)

      const centroid = new THREE.Vector3().add(v0).add(v1).add(v2).divideScalar(3)

      const geo = new THREE.BufferGeometry()
      const verts = new Float32Array([
        v0.x - centroid.x, v0.y - centroid.y, v0.z - centroid.z,
        v1.x - centroid.x, v1.y - centroid.y, v1.z - centroid.z,
        v2.x - centroid.x, v2.y - centroid.y, v2.z - centroid.z
      ])
      geo.setAttribute('position', new THREE.BufferAttribute(verts, 3))
      geo.computeVertexNormals()

      // gradient based on height (bottom = raw cost/black, top = refined value/platinum)
      const tRaw = THREE.MathUtils.clamp((centroid.y / RADIUS + 1) / 2, 0, 1)
      const jitter = (Math.sin(f * 12.9898) * 0.05)
      const t = THREE.MathUtils.clamp(tRaw + jitter, 0, 1)
      const color = gradientColor(t)

      const material = new THREE.MeshPhysicalMaterial({
        color: color,
        metalness: 0.22,
        roughness: 0.14,
        clearcoat: 1.0,
        clearcoatRoughness: 0.06,
        reflectivity: 1.0,
        transparent: true,
        opacity: 0
      })

      const mesh = new THREE.Mesh(geo, material)

      const edgeGeo = new THREE.EdgesGeometry(geo)
      const edgeMat = new THREE.LineBasicMaterial({ color: 0xbfe0ff, transparent: true, opacity: 0.22 })
      const edges = new THREE.LineSegments(edgeGeo, edgeMat)
      mesh.add(edges)

      const dir = centroid.clone().normalize()
      const startPos = dir.multiplyScalar(RADIUS * 3.2)

      mesh.position.copy(startPos)
      mesh.scale.setScalar(0.15)

      group.add(mesh)

      // refined (top, light) facets settle in last — "the cut reveals the value"
      const delay = (1 - t) * 0.5 + t * 0.9
      faces.push({ mesh, material, targetPos: centroid.clone(), startPos: startPos.clone(), delay })
    }

    const ASSEMBLE_DURATION = 1.2
    const ASSEMBLE_TOTAL = 1.9
    const clock = new THREE.Clock()
    let rotationAngle = 0
    let animationFrameId: number

    function easeInOutCubic(x: number) {
      return x < 0.5 ? 4 * x * x * x : 1 - Math.pow(-2 * x + 2, 3) / 2
    }

    function animate() {
      animationFrameId = requestAnimationFrame(animate)
      const elapsed = clock.getElapsedTime()

      for (const f of faces) {
        const local = elapsed - f.delay
        const p = THREE.MathUtils.clamp(local / ASSEMBLE_DURATION, 0, 1)
        const e = easeInOutCubic(p)
        f.mesh.position.lerpVectors(f.startPos, f.targetPos, e)
        f.mesh.scale.setScalar(THREE.MathUtils.lerp(0.15, 1, e))
        f.material.opacity = e
      }

      const rotateProgress = THREE.MathUtils.clamp((elapsed - ASSEMBLE_TOTAL * 0.6) / 1.2, 0, 1)
      const speed = 0.5 * easeInOutCubic(rotateProgress)
      rotationAngle += speed * (1 / 60)
      group.rotation.y = rotationAngle
      group.rotation.x = Math.sin(elapsed * 0.15) * 0.09

      const sweepAngle = elapsed * 0.6
      sweep.position.set(Math.cos(sweepAngle) * 4, Math.sin(sweepAngle * 0.7) * 3, Math.sin(sweepAngle) * 4)

      renderer.render(scene, camera)
    }

    animate()

    return () => {
      window.removeEventListener('resize', resize)
      cancelAnimationFrame(animationFrameId)
      renderer.dispose()
      badge.removeChild(renderer.domElement)
    }
  }, [])

  return (
    <div id="stage">
      <div id="badge" ref={containerRef}>
        <div id="ring"></div>
        <div id="wordmark-wrap" className={showText ? 'show' : ''}>
          
          
        </div>
      </div>
    </div>
  )
}

export default App
