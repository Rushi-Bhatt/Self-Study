var express=require("express");
var http = require("http");
var app=express();
var server=http.createServer(app).listen(3000); //create http server based on express application
var io=require("socket.io")(server); //socket.io is a function and you need to pass the server to which it needs to listen as an argument

app.use(express.static("./public")); //middlewear that serves local static file
io.on("connection",function(socket){ //One socket connection as an endpoint - as soon as the client connects

	socket.on("chat",function(message){ //When the client emits chat event, we are handling that here
		socket.broadcast.emit("message",message);  //broadcast the message event to all the clients
	});
	socket.emit("message","Welcome to the cyber chat"); //instead of sending the message, we are emitting the special kind 
														//of message event from the server, which we are handling in the client side
});
console.log("socket app started at 3000");