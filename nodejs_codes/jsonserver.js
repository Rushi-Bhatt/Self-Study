//Returning the JSON data to the client application
///Any app that can create an HTTP request can have access to this JSON data

var http=require("http");
var data = require("./data/inventory");   //IMP - JSON data can be fetched using require() function

http.createServer(function(req,res){
	if(req.url==="/"){
		res.writeHead(200,{"Content-Type":"text/json"});	//see the content type is text/json
		console.log("TotalData");
		res.end(JSON.stringify(data));  //REMEMBER TO USE - JSON.stringify - data should be a string or a buffer - not json
	}
	else if(req.url==="/instock"){
		inStock(res);
	}
	else if(req.url==="/onorder"){
		onOrder(res);
	}
	else{
		res.writeHead(404,{"Content-Type":"text/plain"});
		res.end("Data  not found");
	}

}).listen(3000);
console.log("Listening to 3000...");

function inStock(res){
	var inStock=data.filter(function(item){  //IMP - filter function- takes a call back function as an argument and that functon will access each
											//item of the data- based on the return value of true/false, that iter will be filtered out from the data
	return item.avail==="In stock";										

	});
	res.end(JSON.stringify(inStock));
}


function onOrder(res){
	var onOrder=data.filter(function(item){  //IMP - filter function- takes a call back function as an argument and that functon will access each
											//item of the data- based on the return value of true/false, that iter will be filtered out from the data
	return item.avail==="On back order";										

	});
	res.end(JSON.stringify(onOrder));
}