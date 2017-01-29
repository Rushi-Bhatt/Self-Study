var express = require("express");
var router = express.Router();  //To create a router object that we can use in place of app -  and that we can export to the demoapp
router.get("/chat",function(req,res){

	res.render("chat", {  //set feeback.ejs as the render template
		pageTitle:"Chat",
		pageID:'chat'
		
	});  ///IMP - res.render(view-name, additonal data to pass to the view) -  to render the view

	 //Since we have set the views in app.set, it automatically looks in the views folder to find index
});

module.exports = router;  //Export the router object