//Mock the data

var expect= require("chai").expect;
var rewire = require("rewire");
var order=rewire("../test_lib/order");  //IMP - instead of require, rewire is used, which will help us inject private/public data 
//into the SUT  - order module in our case. So we can change the inventory data with our mock data

var sinon=require("sinon"); //To mock the function -here console log function

describe("Ordering Items",function(){
	beforeEach(function(){  //this hook will execute the callback function before each test
		this.testData = [   //setting the test data for the tests, reason for using this(mocha object reference) is to use the same
  		{sku:"AAA",qty:10},	//data elsewhere in the test if need be.
		{sku:"BBB",qty:0},
		{sku:"CCC",qty:3}
		];	

		this.console={  //fake console object
			log: sinon.spy() //fake log function
		};

		this.warehouse = {
			packageAndShip:sinon.stub().yields(1098765) //fake stubbed packageAndShip function 
		};

		//we will also have to tell the stub that packageAndShip needs to invoke a callback function and pass the tracking number
		//as an argument - That is done here by yields(arg) 

		order.__set__("inventoryData",this.testData);  // __set__ - set the data of variable in the SUT	
		order.__set__("console",this.console);  // __set__ - set the console to fake console
		order.__set__("warehouse",this.warehouse); //__set__ - set the warehouse to mock warehouse

	});

	it("logs item not found",function(){
		order.orderItem("ZZZ",10);
		expect(this.console.log.calledWith("Item - ZZZ not found")).to.equal(true);
	});

	it("should order an item if enough available",function(done){
		//Orering an item is an async function as it calls warehouse and packing ...So we need to use done to tell the test to run
		//we also need to check whether the console.log is called twice (as it is supposed to as per order.js) for our fake console

		var _this=this;
		order.orderItem("CCC",3,function(){
			expect(_this.console.log.callCount).to.equal(2); //.callCount - # of function calls
			done();
		});
	});

	describe("warehouse Interaction",function(){
		beforeEach(function(){
			this.callback=sinon.spy();
			order.orderItem("CCC",2,this.callback);
		});

		it("receives a tracking number",function(){
			expect(this.callback.calledWith(1098765)).to.equal(true);  //callback function should be called with the fake tracking number
		});

		it("calls packageAndShip with the proper sku and qty",function(){
			expect(this.warehouse.packageAndShip.calledWith("CCC",2)).to.equal(true);
		});
	});
});

