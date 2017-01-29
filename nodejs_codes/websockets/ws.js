var webSocketServer=require("ws").Server;
var wss = new webSocketServer({port:3000}); //creating the web socket server

wss.on("connection",function(ws){   //On connection request from every client to the socket server, ws represent the socket
	ws.on("message",function(message){     //on message - when client sends a message to the server socket
		if(message==="exit"){
			//close that perticular client socket, but keep the server running
			ws.close(); //close the socket
		}
		else{
			wss.clients.forEach(function(client){   //IMP - wss.clients - Array of all the clients connected to the server
				client.send(message);              //broadcast the message to all the clients
			});

		}
	});
	console.log("socket server listening to 3000");
	ws.send("Welcome to cyber chat");   //send the message to the socket - this will ultimately be sent to the client when they connect to socket
});
