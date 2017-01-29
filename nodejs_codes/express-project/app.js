//Creating a file server for public directory

var expvar=require("express");  //You dont have to specify the path of installed packages- nodejs will take care of that.You can 
								 //directly use them as if they were core modules
var cors=require("cors"); //Cross Origin Resource Sharing 
var bp=require("body-parser");// Middlewear that ll help y ou parse the post data

var app=expvar();//new instance of an express application


//add data to the dictionary and make it accessible via route /dictionary-api 
var skidata=[
{
	term:"a",
	defined:"A"
},
{
	term:"b",
	defined:"b"
},
{
	term:"c",
	defined:"C"
},
];

app.use(bp.json()); //If we have our data sent to API as json, we ll parse that data - generally REST apps post data as json
app.use(bp.urlencoded({extended:false})); //If we have our data sent to API as urlencoded, we ll parse that data - generally html forms post data as urlencoded

//extended:true only if you have larger amount of nested data
//once you parse the post data- it will be available in req.body object as a proper formatted json

app.use(function(req,res,next){
	//Its a callback function in the app pipeline meaning, whenever any request is generated, this function will be called and 
	//after handling this, we need to give the next function to jump to next app.use 
	console.log(`${req.method} request for ${req.url} - ${JSON.stringify(req.body)}`); //req.body - Post data
	next();  //For next middlewear in line
});
app.use(expvar.static("./public")) ; // .use -  to include any middleware to your express application
//Express.static will invoke the static file server that comes with Express, and we're going to add it to our app pipeline as a piece of middleware.
//takes as an argument the directory name from which the static content is to be fetched


//add data to the dictionary and make it accessible via route /dictionary-api
app.use(cors()); //Any domain can make request to our dictionary-api, not just localhost:3000
app.get("/dictionary-api",function(req,res){
	//Note that this req and res are different annd more powerful than http req and res
	//for exp res has a function json which can directly put json object as a response without writeHead and end 
	res.json(skidata); //automatically stringify and setting header
});//Setup the get route - route, callback function

app.post("/dictionary-api",function(req,res){   ///when we add new term to the dictionary 
	skidata.push(req.body);  //req.body will have the post data
	res.json(skidata);
});

app.delete("/dictionary-api/:term",function(req,res){ //when we double click on term - delete requests
	//:term - whatever the value of delete request parameter, it will be stored in this term param
	// and can be accessed using req.param.term
	skidata= skidata.filter(function(item){
		return item.term.toLowerCase()!==req.params.term.toLowerCase();
	});
	res.json(skidata);
});
app.listen(3000);
console.log("express app on port 3000");
module.exports=app; //To include this module in other file  //supertest module can directly use this module by importing the app


