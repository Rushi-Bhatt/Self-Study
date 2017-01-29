var express = require("express");
var router = express.Router();  //To create a router object that we can use in place of app -  and that we can export to the demoapp
//var datafile  = require("../data/data.json"); -  instead of doing this, we are gonna get it from application

router.get("/speakers",function(req,res){
	/*var info="";
	var datafile=req.app.get("appData");     //IMP: app directly wont be accessible, you need to use it as req.app.get
	datafile.speakers.forEach(function(item){
		info+= `
		<li>
		<h2>${item.name}</h2>
		<img src="/images/speakers/${item.shortname}_tn.jpg" alt="speakers">
		<p>${item.summary}</p>
		</li>
		`;
	});
	//dont forget to include the reload script 
	res.send(`
			<link rel="stylesheet" type="text/css" href="/css/style.css">  
			<h1>Details of all the speakers</h1>
			${info} 
			<script src="/reload/reload.js"></script>   
			`);      		//Send  -  to send response to the client
*/

//lets use the template to create the respose 
	var data=req.app.get("appData");
	var pagePhotos=[];
	var pageSpeakers = data.speakers;

	data.speakers.forEach(function(item){
		pagePhotos=pagePhotos.concat(item.artwork);
	});

	res.render("speakers", {
		pageTitle:"Speakers",
		artwork: pagePhotos,  //sending the data to the view
		pageID:'speakerList',
		speakers:pageSpeakers   
	});  ///IMP - res.render(view-name, additonal data to pass to the view) -  to render the view

	 //Since we have set the views in app.set, it automatically looks in the views folder to find index

});

router.get("/speakers/:id",function(req,res){
	/*var datafile=req.app.get("appData");
	var speaker = datafile.speakers[req.params.id];   //req.params -  access the variable passed from the URL
	 //Start the route with / - it indicates the root -  for link ang img tag here	
	res.send(`
			  <link rel="stylesheet" type="text/css" href="/css/style.css"> 	
			  <h1>Details of the requested individual speaker</h1>
			  <h2>${speaker.title}</h2>
			  <h3>${speaker.name}</h3>
			  <img src="/images/speakers/${speaker.shortname}_tn.jpg" alt="speaker">
			  <p>${speaker.summary}</p>
			  <script src="/reload/reload.js"></script>
			`);      		//Send  -  to send response to the client*/

//lets use the template to create the respose 
	var data=req.app.get("appData");
	var pagePhotos=[];
	var pageSpeakers =[];

	data.speakers.forEach(function(item){
		if(item.shortname == req.params.id){   //Only for the selected speaker
			pageSpeakers.push(item);
			pagePhotos=pagePhotos.concat(item.artwork);	
		}
	});

	res.render("speakers", {
		pageTitle:"Speaker Info",
		artwork: pagePhotos,  //sending the data to the view
		pageID:'speakerDetail',
		speakers:pageSpeakers   
	});  ///IMP - res.render(view-name, additonal data to pass to the view) -  to render the view

	 //Since we have set the views in app.set, it automatically looks in the views folder to find index


});
module.exports = router;  //Export the router object