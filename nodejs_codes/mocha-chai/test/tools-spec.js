//mocha doesnt give a way to check values, so we need an assertion engine for that
///Thats where chai is used

var expect = require("chai").expect;
var tools = require("../test_lib/tools");  //We are assuming that the printName function will be in the tools module in lib dir
var nock = require("nock");

describe("Tools",function(){

	describe("printName()",function(){
		it("should print the last name first", function(){
			var results=tools.printName({first:"Rushi", last:"Bhatt"}); //We are assuming that we already have the function printName
			expect(results).to.equal("Bhatt,Rushi");  //We are expecting the result to be like this
		}); //To stub your test
	});

//Asynchronous mocha testing
// Sometimes the functions that we need to test need a little bit more time to operate. 
//A good example of this is the web request. When we request a web page, it's going to take a little bit of time to 
//download that page before the task is complete
//we have to tell mocha to wait before running the test

/*	describe("loadWiki()",function(){

		this.timeout(5000);  //this: mocha object - It will wait 5 seconds to run any async tests(reading the page)
		it("should load the abraham lincoln's wikipedia page", function(done){  //done is  used to wait for callback fuction
			tools.loadWiki({first:"Abraham",last:"Lincoln"},function(html){  //callback function becoz its an async call
				expect(html).to.be.ok;       //I want that  html content of  wiki to be okay before I run the test
				done(); 					 
			});	

		});

	});*/
	
	//Here our test depends on the wikipedia server and thats why it is taking so much time in the above example
	//nock helps us create mock servers that we can use for such purposes
	///mocha-hooks - code to run before or after every test, so create one before code and create mock server in that

	describe("loadWiki()",function(){

		before(function(){   //takes a callback function which will be called before 'it'
			nock("https://en.wikipedia.org").get("/wiki/Abraham_Lincoln").reply(200,"Mock Abraham Lincoln");
		});

		//this.timeout(5000);  //we dont need this now as it wont  take longer than 2s
		it("should load the abraham lincoln's wikipedia page", function(done){  //done is  used to wait for callback fuction
			tools.loadWiki({first:"Abraham",last:"Lincoln"},function(html){  //callback function becoz its an async call
				expect(html).to.be.equal("Mock Abraham Lincoln");       //I want that  html content of  wiki to be same as reply of nock
				done(); 					 
			});	

		});

	});




	

});


