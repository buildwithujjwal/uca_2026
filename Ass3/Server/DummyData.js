import * as http from "http";

// http is a module
// module is a object from which we can use some properties

let value = "Hello world!";
console.log("Node.js first program\n" + value);

// dummy data
const users = [
  { id: 1, name: "Tom", status: "Active" },
  { id: 2, name: "John", status: "Inactive" },
  { id: 3, name: "Jerry", status: "Active" },
  { id: 4, name: "Alice", status: "Inactive" },
  { id: 5, name: "Bob", status: "Active" },
];

// create a local server to recieve data from 
const server = http.createServer((req, res) => {

    res.writeHead(200, {
      "content-type": "application/json",
      "Access-Control-Allow-Origin": "*",
    });

    if (req.url == "/users") {
      res.end(JSON.stringify(users));
    }
    else {
        res.end(    JSON.stringify({
            name: "Ujjwal",
            response: "Hello world! from Node.js server",
          }),
        );
    }
    
  
});

const hostname = "127.0.0.1";
const port = 5000;
server.listen(port, hostname, () => {
    console.log(`Server is running at http://${hostname}:${port}/`);
});
