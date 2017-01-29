//console object
var hello="Hi";
console.log(hello);
global.console.log("Hello");
console.log(__dirname); ///current directory name with entire path
console.log(__filename); //current filename with entire file

//process object
console.log(process.argv); //process.argv - Array containing the node and file address initially
//All the data passed from termial are stored here in the array
//function to grab the value of flag
function grab(flag){
	var index=process.argv.indexOf(flag);
	return (index===-1)? null:process.argv[index+1];
}
console.log(grab('--user'));

//Std output and std input object
process.stdout.write("Hello");
process.stdout.write("World \n");             //output - Hello world (and then 3 new lines); stdout doesnt automatically give new lines, you 
process.stdout.write("Line about to be deleted"); //have to mention it using \n 
process.stdout.clearLine();                       //Clears the last line in the terminal
process.stdout.cursorTo(0);                       //Set the cursor to the beginning of the line
process.stdout.write("New text");
/*process.stdout.write("\nWhat is your name? > ");
process.stdin.on('data',function(data){    //Data event - When user types something in terminal and hit enter, data event triggers
	process.stdout.write('\nHi '+data.toString().trim()+'\n');
	process.exit(); //To exit the process
});									  

process.on('exit',function(){              //Exit event - When process.exit invokes, this mehod will be called
	process.stdout.write("\n\n Exiting...Bye");
});
*/

//Core Modules
//path module- one of the core modules
var path=require("path"); 
console.log(`${path.basename(__filename)}`); //Just the file name
var uploadDir=path.join(__dirname,"www","files","upload"); //Join mehtod to join the paths
console.log("Console.log::Upload directory::"+uploadDir);

//utiity module -  one of the core modules
var util=require('util');
util.log("Util.log::Upload directory::"+uploadDir); //Also gives date and time stamp, unlike console.log

//v8 module -  one of the core modules - gives memory information
var v8=require('v8');
util.log(v8.getHeapStatistics()); //Current Memory usage

//readline -  one of the core modules - wrapper around stdin and stdout - prompt user
/*var readline=require('readline');
var rl=readline.createInterface(process.stdin,process.stdout	);
var realPerson={
	name:'',
	sayings:[]
}
rl.question("What is the name of realPerson?",function(name){
	realPerson.name=name;
	rl.setPrompt("What did he say?");  //To set the prompt
 	rl.prompt();                        //To call that prompt
 	rl.on("line",function(saying){      // line event triggers when the user enters the data
 		if (saying.toLowerCase().trim()==="exit"){
 			rl.close();					//To end the async event call
 		}
 		else{
 			realPerson.sayings.push(saying.trim());
 			rl.setPrompt("What else did he say?('exit' to leave)");  //To set the prompt
 			rl.prompt();                        //To call that prompt
 		}
 	});
});
rl.on("close",function(){                            //executes just before rl.close()
	console.log("%s has said %j",realPerson.name,realPerson.sayings);     //%s - String, %j - json string object
	process.exit();
});*/

//events module - Event Emitter - allows you to create custom events for custom objects
var events=require('events');
var emitter= new events.EventEmitter(); //Constructor 
emitter.on('customEvent',function(message,status){ //callback function
	console.log(`${status}: ${message}`);
});

//To trigger the event, event function is used
emitter.emit("customEvent","Message is Hello world",200); //emit(event name, arguments to the callback function)

//now lets do this with inheritance
/*var EventEmitter1 = require('events').EventEmitter;   //instead of 2 separate calls, we can merge them into one //remember: No braces after EventEmitter here
var util=require('util');

var Person= function(name){
	this.name=name
};
util.inherits(Person,EventEmitter1);   //JAVASCRIPT INHERITANCE- PERSON INHERITS FROM EVENTEMITTER- SO PERSON CAN
									   //RESPOND TO ON AND EMIT NOW
var ben= new Person("Ben Franklin");
ben.on('speak',function(said){
	console.log(`${this.name} has said that ${said}`);
});

ben.emit('speak',"I am Mr.Ben Franklin");*/

//Custom module  - export
//Lets say we want to use Person module here without actually copying the code.
var Person = require("./lib/Person"); //Custom module Person - No need of js extension and since its not a core module, we need to give path
var ben= new Person("Ben Franklin");
ben.on('speak',function(said){
	console.log(`${this.name} has said that ${said}`);
});

ben.emit('speak',"I am Mr.Ben Franklin");

//child process module - execute function 
var exec=require("child_process").exec;
//exec("explorer http://www.linkedin.com");
//exec("cmd ."); 
exec("dir",function(err,stdout){     //Anything returned by command is injected in the call back function as arguments
	if(err){
		throw err;
	}
	console.log("Listing finished");
	console.log(stdout);
});
exec("git version",function(err,stdout){     //Anything returned by command is injected in the call back function as arguments
	if(err){
		throw err;
	}
	console.log("git version executed");
	console.log(stdout);
});

//spawn function
var spawn=require("child_process").spawn;
var cp=spawn("node",["alwaysTalking"]); //Syntax: spawn(command, [arguments]) //here always talking is another js file that we want to execute
cp.stdout.on("data",function(data){     //stdout on data will be triggered when childprocess puts something out on terminal
	console.log(`STDOUT:${data.toString()}`);
});

cp.on("close",function(){ //When child process is closed
	console.log("Child process closed");
	process.exit();   //end parent process
});

setTimeout(function(){
	cp.stdin.write("stop");   //stdin.write will give input to the child process as if we are giving input via terminal
},4000);

