import {useRef} from 'react'

function Ref() {
    const get = useRef(null);

    function handleRef(){
        get.current.focus();
    }

  return (
    <div>
      <input type="text" ref={get} />
      <button onClick={handleRef}>save</button>
    </div>
  )
}

export default Ref
