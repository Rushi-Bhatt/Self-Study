//create server using node js
/*
var http= require("http");

http.createServer(function(req,res){
	res.writeHead(200, {"Content-Type":"text/html"});
	res.write("<h1>Hi there</h1>");
	res.end();

}).listen(3000);
console.log("Server listening to 3000");
*/


//Create server using express 
var nd=require("node-dev");
var express=require("express");
var app = express();
var datafile  = require("./data/data.json");
var io=require("socket.io")(); //IMP - See the extra () in the end  //you can pass the server in the () and then you dont have to
//use io.attach(server)


//with express, you can access the environment variables, so lets not hardcode the port to 3000, rather lets fetch it 
//from the environment variable

var reload = require("reload"); // To reload the browser when the app restarts the server

app.set('port',process.env.PORT || 3000);  //process.env - environment variables  - PORT - port, if its not specified, default 3000
app.set("appData",datafile);  //Access to the entire application, so in speaker.js, we can access it using app.get("appData")

app.set("view engine","ejs"); //setting the view engine to ejs
app.set("views","./views"); //Location of views folder

app.locals.siteTitle="Rushi's site"; //Set local variable that is accessible thru all the pages .. just using <%= siteTitle %>
app.locals.allSpeakers = datafile.speakers;

app.use(require("./routes/index")); //Route modularization  - IMP: Synrax: app.use(), not app.get()
app.use(require("./routes/speakers")); //Route modularization
app.use(require("./routes/feedback")); //Route modularization
app.use(require("./routes/api")); //Route modularization
app.use(require("./routes/chat")); //Route modularization

app.use(express.static('./public')); //IMP: express.static() - middleware that allows you to designate a folder that is accessible through entire application
//this mentioned folder becomes the root , so in any other js, you can access the files inside the mentined folder by giving path	

var server = app.listen(app.get('port'),function(){
io.attach(server);  //attach the server to the socket-io

io.on("connection",function(socket){
	console.log("User connected");
	socket.on("postMessage",function(data){ //handle the event emitted by the client on conenction
		io.emit('updateMessages',data); //Emit the updateMessages event
	});
	socket.on("disconnect",function(){
		console.log("User connected");	
	});


});
console.log("Server listening to the port: "+app.get('port'));

});  //instead of listen 3000, listen to app.get('port');


reload(server,app); // reload .. we still need to add the reload script in all js that tells browser to reload