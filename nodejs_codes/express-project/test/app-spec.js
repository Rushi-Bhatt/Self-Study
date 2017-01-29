var request = require("supertest"); //request is a function that we can use to make http request
var expect = require('chai').expect;
var cheerio = require('cheerio');
var rewire = require('rewire');
var app = rewire('../app');

describe("Dictionary App", function () {

   /* it("Loads the home page",function(done){
        request(app).get("/").expect(200).end(done); //Async request call , so we need to tell mocha when the supertest is done
    });*/

    //Test the html response with cheerio
    it("Loads the home page",function(done){
        request(app).get("/").expect(200).end(function(err,res){
            var $ = cheerio.load(res.text);
            var pageHeading = $("body>h1:first-child").text();  //just like jquery, you can access the DOM elements
            expect(pageHeading).to.equal("Skier Dictionary");
            done();

        }); //Async request call , so we need to tell mocha when the supertest is done
    });

    describe("Dictionary API", function () {

        beforeEach(function () {

        	this.defs = [
                {
                    term: "a",
                    defined: "A"
                },
                {
                    term: "b",
                    defined: "b"
                },
                {
                    term: "c",
                    defined: "C"
                }
            ];

            app.__set__("skierTerms", this.defs);
        });

        /*it("GETS dictionary-api",function(done){
            request(app).get("/dictionary-api").expect(200).end(done); //Async request call , so we need to tell mocha when the supertest is done
        
        }); */

        //we also want to check the server response by checking the data returned from the  server - by get request
        //For that, following code -
        it("GETS dictionary-api",function(done){
            var defs=this.defs;
            request(app).get("/dictionary-api").expect(200).end(function(err,res){
                //supertest will generate the callback function and then it will pass an error and response in that callback function
                
                //Test the JSON responnse by parsing
                var terms=JSON.parse(res.text);  //data that we get as a response
                expect(terms).to.deep.equal(defs); //deep.equal  - to compare two objects
                done();
            });
        
        });

        it("POSTS dictionary-api",function(done){
            request(app).post("/dictionary-api")
                        .send( {term: "c",defined: "C"})  //Data sent along with the post request
                        .expect(200).end(done); //Async request call , so we need to tell mocha when the supertest is done
        });

        it("DELETES dictionary-api",function(done){
            request(app).delete("/dictionary-api/a").expect(200).end(done); //Async request call , so we need to tell mocha when the supertest is done
        });

    });

});