const ww1 = new Worker("./js/Q27worker.js");

ww1.postMessage("http://127.0.0.1:5000/users");    

ww1.onmessage = function(event) {
    event.data.forEach((user) => console.log(user.name + " - " + user.status));
}