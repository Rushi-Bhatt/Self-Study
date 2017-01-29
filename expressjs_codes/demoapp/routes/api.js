var express = require("express");
var router = express.Router();  //To create a router object that we can use in place of app -  and that we can export to the demoapp
var feedbackData = require("../data/feedback.json");  
var bodyParser = require("body-parser");
var fs=require("fs");

router.get("/api",function(req,res){
	res.json(feedbackData);    //IMP - res.json - Output the json data
	
});

//Body parser settings
router.use(bodyParser.json());
router.use(bodyParser.urlencoded({extended:false}));  //forms are urlencoded and simple forms , so extended false

router.post("/api",function(req,res){
	feedbackData.unshift(req.body); //IMP - unshit - because we want to add that data on the top, not bottom
									//req.body - Data of the post  request
	
	//We also need to save the new feedback in the file so that if we restart the server, it gets the data from the json file and 
	//if that json file is not updated with new data, we ll lose that feedback

	fs.writeFile("./data/feedback.json",JSON.stringify(feedbackData),"UTF-8",function(err){
		if(err) console.log(err);
	});

	res.json(feedbackData);			//IMP - res.json - Output the json data
});

///delete route
router.delete("/api/:id",function(req,res){
	feedbackData.splice(req.params.id,1); 
	fs.writeFile("./data/feedback.json",JSON.stringify(feedbackData),"UTF-8",function(err){
		if(err) console.log(err);
	});

	res.json(feedbackData);			//IMP - res.json - Output the json data
});

module.exports = router;  //Export the router object