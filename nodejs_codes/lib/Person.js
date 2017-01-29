var EventEmitter1 = require('events').EventEmitter;   //instead of 2 separate calls, we can merge them into one //remember: No braces after EventEmitter here
var util=require('util');

var Person= function(name){
	this.name=name
};
util.inherits(Person,EventEmitter1);   //JAVASCRIPT INHERITANCE- PERSON INHERITS FROM EVENTEMITTER- SO PERSON CAN
									   //RESPOND TO ON AND EMIT NOW

module.exports=Person;   //This is a JS object which is returned in require