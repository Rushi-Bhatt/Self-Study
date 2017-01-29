
var express = require("express");
var router = express.Router();  //To create a router object that we can use in place of app -  and that we can export to the demoapp
router.get("/",function(req,res){
	//Start the route with / - it indicates the root  - img and link command
	/*res.send(`
			  <link rel="stylesheet" type="text/css" href="/css/style.css">  
			  <h1>Hi there.. this is the welcome page for my site</h1>
			  <img src="/images/misc/background.jpg" alt="background" style="height:300px">
			  <script src="/reload/reload.js"></script>
			`);      		//Send  -  to send response to the client*/

	//Instead of creating the response, lets use the view  - index.ejs template
	
	var data=req.app.get("appData");
	var pagePhotos=[];
	var pageSpeakers = data.speakers;
	
	data.speakers.forEach(function(item){
		pagePhotos=pagePhotos.concat(item.artwork);
	});

	res.render("index", {
		pageTitle:"Home",
		artwork: pagePhotos,  //sending the data to the view
		pageID:'home',
		speakers:pageSpeakers
	});  ///IMP - res.render(view-name, additonal data to pass to the view) -  to render the view

	 //Since we have set the views in app.set, it automatically looks in the views folder to find index


});

module.exports = router;  //Export the router object