//collecting post data
var http=require("http");
var fs=require("fs");
 http.createServer(function(req,res){
 	if(req.method==="GET"){
 		//normal get request - display the form
 		res.writeHead(200,{"Content-Type":"text/html"});
 		fs.createReadStream("./form/form.html","UTF-8").pipe(res); //directly piping the read stream to res
 	}
 	else if(req.method==="POST"){
 		//form posted - get the form data from request , and display confirmation message/html as response
 		var body="";
 		req.on("data",function(chunk){  //Collect the form data which is coming with the post request
 			body+=chunk;
 		});
 		req.on("end",function(){    //When the post request is ended, show the html form submitted confirmation page
 			res.writeHead(200,{"Content-Type":"text/html"});  //Notice the content type is HTML
 			res.end(`<!DOCTYPE html>  
 				<html>
 				<head>
 				<title>Submitted</title>
 				</head>
 				<body>
 				<h1>Form submitted successfully</h1>
 				<p>${body}</p>
 				</body>
 				</html>	
 				`);
 		});
 		
 	}
 }).listen(3000);
console.log("listening to 3000"); 