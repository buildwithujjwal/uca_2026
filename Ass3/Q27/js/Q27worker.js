async function getUsers(url) {
    try{
        const response = await fetch(url);

        if(!response.ok) {
            throw new Error(`HTTP Error : ${response.status}`);
        }

        const data = await response.json();
        self.postMessage(data);
    }
    catch(error) {
        console.error('API called failed : ', error);
        return null;
    }
}

self.onmessage = function (event) {
    const result = getUsers(event.data);
}