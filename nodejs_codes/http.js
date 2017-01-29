//Making HTTPS request
var https=require("https");
var fs=require("fs");
var options={
	hostname:"en.wikipedia.org",
	port:443,
	path:"/wiki/George_Washington",
	method:"GET"

};

//res object automatically creates the read stream and we can use on data, once data and 'on end' on the res object to read the chunks
var req = https.request(options,function(res){     //https.request(option object, callback function)
	var responseBody="";
	console.log("Response started...");
	console.log("Server status : "+res.statusCode);  //res.statusCode - Status of server
	console.log("Response Header : %j",res.headers); //res.headers - Response Header
	res.setEncoding("UTF-8");                        //res.setEncoding - set the text encoding to UTF 8 

	res.once("data",function(chunk){
		console.log("First chunk - "+chunk+"\n");
	});
	res.on("data",function(chunk){
		console.log("Chunk--:"+chunk.length);
		responseBody+=chunk;
	});
	res.on("end",function(){
		fs.writeFile("George_Washington.html",responseBody,function(err){
			if(err){
				throw err;
			}
			else{
				console.log("File downloaded");
			}
		});
	});
});

req.on("error",function(err){				//req.on "error"
	console.log("Error with the request::"+err);
});
req.end();                               //req.end() - To end the request

//Making HTTP Web server(No need of certificate)
var http=require("http");
//Every time a request to server is made, the call back function in createServer is invoked
//req - headers, data going along with the request, user info(environment etc.)
//res - blank response object - which we will fill by writing the headers using writeHead() and writing data using res.end(data)
var server=http.createServer(function(req,res){
	res.writeHead(200,{"Content-Type":"text/html"});	//writeHead(res server status, response header);
	res.end(`
		<!DOCTYPE html>
		<html>
		<head>
			<title>HTML Response</title>
		</head>
		<body>
			<h1>Serving HTML file</ht>
			<p>${req.url}</p>      //req.url  - url from which the request has been created for the server
			<p>${req.method}</p>   //req.method - request method - mostly get when we make server request from browser, unless we are posting a form
		</body>
		</html>
	`);    //response data - It is out job to determine the url path from request object and provide with the appropriate 
	// html data/file in the response object. For that we need to access the req object url

});

server.listen(3000); //listen(port) - Tell server to listen to port 3000
console.log("Server started..Listening to port 3000...");