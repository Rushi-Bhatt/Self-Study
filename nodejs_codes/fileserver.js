//Creating a file server that responds to localhost 3000 - serving files
var http=require("http");
var fs=require("fs");
var path=require("path");

http.createServer(function(req,res){
	console.log(`${req.method} request for ${req.url}`);
	if(req.url==="/"){
		fs.readFile("./public/index.html","UTF-8",function(err,content){
			if(err){
				throw err;
			}
			else{
				res.writeHead(200,{"Content-Type":"text/html"});
				res.end(content);		
			}
		});	
	}
	else if(req.url.match(/.css$/)){		//.match - javascript func to match the string with regex
		//Read the css file of public directory
		var cssFilePath=path.join(__dirname,"public",req.url);
		//reading with stream insted of file.readFile
		var cssFileStream = fs.createReadStream(cssFilePath,"UTF-8");
		res.writeHead(200,{"Content-Type":"text/css"});   //See the content type is css for this
		cssFileStream.pipe(res);     //pipe method - readStream.pipe(writeStream) and res is of type writeStream 
	}
	else if(req.url.match(/.jpg$/)){		//.match - javascript func to match the string with regex
		//Read the css file of public directory
		var imgFilePath=path.join(__dirname,"public",req.url);
		//reading with stream insted of file.readFile
		var imgFileStream = fs.createReadStream(imgFilePath); //REad the file as binary stream - not a text file
		res.writeHead(200,{"Content-Type":"image/jpeg"});   //See the content type is image/jpeg for this
		imgFileStream.pipe(res);     //pipe method - readStream.pipe(writeStream) and res is of type writeStream 
	}
	else{
		res.writeHead(404,{"Content-Type":"text/plain"});
		res.end("404 File not found..");
	}
}).listen(3000);
console.log("Listening to port 3000...");