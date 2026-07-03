import {useState, useEffect} from 'react'
const URL = 'https://jsonplaceholder.typicode.com/users'
function api() {
const [detail, setDetail] = useState([]);


useEffect(() => {
    const getData = async () => {
        const response = await fetch(URL);
        const data = await response.json();
        setDetail(data);
    };

    getData();
}, []);


console.log(detail);



  return (
    <div>
      
    </div>
  )
}

export default api
