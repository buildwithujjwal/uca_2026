const ww1 = new Worker("../Q27/js/Q27worker.js");

ww1.postMessage('http://127.0.0.1:5000/users');
ww1.onmessage = function (event) {
    const users = event.data;

    const html = users
        .map((user) => `${user.name} - ${user.status}`)
        .join("<br>");

    document.getElementById("users").innerHTML = html;
}