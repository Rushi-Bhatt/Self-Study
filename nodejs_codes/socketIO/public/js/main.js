//Dont forget to include socket-io.client.js to the index.html and your js folder
//You can download it online
//socket-io client takes care of the situation where the sockers are not supported by your browser

var socket=io("http://localhost:3000");
socket.on("connect",function(){
    setTitle("Connected to Cyber Chat");
});

socket.on("disconnect",function(){
    setTitle("DISCONNECTED");
});

socket.on("message",function(message){  //message event is emitted by the server
    printMessage(message);
});

document.forms[0].onsubmit = function () {
    var input = document.getElementById("message");
    printMessage(input.value);
    socket.emit("chat", input.value);  //chat event is handled by the server
    input.value = '';
};

function setTitle(title) {
    document.querySelector("h1").innerHTML = title;
}

function printMessage(message) {
    var p = document.createElement("p");
    p.innerText = message;
    document.querySelector("div.messages").appendChild(p);
}
