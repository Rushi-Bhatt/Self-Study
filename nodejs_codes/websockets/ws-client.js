//native js
var ws=new WebSocket("ws://localhost:3000"); //Create new websocket (arg = websocket server url)
ws.onopen=function(){	//ws.onopen - when the web socket opens
	setTitle("Connected to cyber chat");
};
ws.onclose=function(){	//ws.onlcose  -when the web socket closes
	setTitle("DISCONNECTED");
};
ws.onmessage=function(payload){	///ws.onmessage - when the web socket receives the message
	printMessage(payload.data);  //IMP - .data
};

document.forms[0].onsubmit=function(){
	var input=document.getElementById("message");
	ws.send(input.value); //send the message to the socket server
	input.val='';
};
function setTitle(title){
	document.querySelector("h1").innerHTML=title;
}

function printMessage(message){
	var p=document.createElement("p");
	p.innerHTML=message;
	document.querySelector("div.messages").appendChild(p);
}
