let abc:string="pickup";
let a:string = "abc";
let b:string = "bcsd";
let c:string="anana";

//1)Optimal parameters
//Give default values to parameter in the type script, so rather than ignoring the values, javascript will check if the value
//is passed..If not, then it will consider the default value, else the passed value

function timer(initial,final1,interval=1){
	console.log(initial);
	console.log(final1);
	console.log(interval);
}
timer(10,0);

//2)Template Strings
var container=document.getElementById("#container");
var todo={
	id:123,
	name:"Pick up ben",
	completed:true
}
var displayName=`ToDo #${todo.id}`;

//3)let and const keyword
for(var x=0;x<5;x++){
	 let count=x;
	 const c1=x; 
	///c1=1;    // this will give error as we have used const, so c cant be changed once assigned 
}
//console.log(count);  this will give error as we have used let, so count is not accessible outside the for loop 

//4) for of syntax that lets you loop over the elements of array without having to use the syntax

var array=["pickup ben","pay the bill","eat and sleep"];
for(var index in array){
	var task=array[index];
	console.log(`${index} : ${task}`);
}
for(var task of array){
	//var task=array[index];         //Dont need this now
  	console.log(`${task}`); 
}

//5) Lambda expression - Arrow function
var filtered=[1,2,3].filter( x => x>2);
console.log(filtered);


//6)Destructuring 
var array1=[123,"pickup",true];
var [id1,task1,completed1]=array1;
var [id2,task2,completed2]=[124,"eat",true];
console.log(id2);
  //same can be used for .. [a,b]=[b,a] - interchanging the values
  //same can be used for objects as well where the values are compared with the keys
  
var xyz={
	x:123,
	w: true,
	y:"sleep",
	z:false
}
var {x,y,z}=xyz;
console.log(x,y,z);
//same works for return value - very important
// you can change the variable name as well, by specifying it with : sign
function temp1(){
	var abcd={
		a:123,
		b: true,
		c:"sleep",
		d:false
	}
	return abcd;

}
var {a: A, b:B, c:C, d:D} = temp1();
console.log(A,B,C,D);

//7)Spread operator // function that takes any number of arguments
function calculate(action, ...values){                 // ...values  is same as *args python
	var total=0;
	for(var value of values){
		switch(action){
			case 'add':
				total+=value;
				break;

			case 'sub':
				total-=value;
				break;	
		}
	}
	return total;
}
console.log(calculate('add',1,2,5,4,6));
//another use is to concat two arrays directly  - Very important
var ar1=[1,2,3];
var ar2=[4,5,/*Insert that array here*/,6,7];
ar2=[4,5,...ar1,6,7];
console.log(ar2);
ar2.push(...ar1); //Concate two arrays
console.log(ar2);

//type fundamentals: 1)null/undefined 2)string, number, boolean - immutables 3)objects- array, functions, date, regex etc.
//type inference - ability of type script to detect the type of object on the fly.. so it will sense the type of name as string
// since we assigned a value of string to the name. Thefore , when we assign the value as 1, it will give error
var animal={
	name:"frodo",
	age:calculateAge(2010),
	speak:function(){                   //function as a value
		console.log('woof!');
	}
}

//animal.name=1;   //ts will give error as 1 is number, not string
//same can be true for function return type
//ts will detect the return type of calculateaAge as number, because the Date.now is of type number
function calculateAge(birthyear){
	return Date.now() - birthyear;
}
 //When the ts doesnt recognize the type of any expression, it sets it as 'any' - most dynamic loose type- same as javascript
 ///for exp.. here the return type of tlength is 'any'
 function tlength(x,y){
 	return x.length+y.length;   //if y.len, then also it wont give any error - coz it doesnt know the type
 }

 //So to avoid this, we need to provide the type of each object - So that type script can check the sentence for ay error
 function totalLength(x:any[],y:string):number{
 	var total:number = x.length+y.length;                   //any[] - array of objects of any type - since we only are considering 
  	return total;    										//length, we dont care about the type

 }

 // Unioun type - | operator 
 function totalLengthWithUnioun(x:(string|any[]),y:(string|any[])):number{
 	var total:number = x.length+y.length;                //Since string and any[] both are having the length property  
  										                 // the code will work.. infact it will give some of the common methods	
   // as suggestions, but if we access any member which is not present for any one type, typescript will give error. To avoid that, 		
 	
 	if(x instanceof Array){     //This is called type guard syntax -  which checks the type of param, and do differnt things based on type
 		x.push("abc");
 	}
    if(x instanceof String){
 		x.substr(1);	
 	}
    return total;    
 }

//Funtion overloading in javascript - lets say we want to separate the above function into two different
//function totalLengthWithUnioun(x:(any[]),y:(any[])):number{  }
//function totalLengthWithUnioun(x:(string),y:(string):number{	}
//But this wont work in javascript, as it goes from top to bottoma dnd rewrite the first definition with the second one -
// So how to overload ? just put both the defintion  above the actual code
//So in suggestion, it will only allow you to have either of the two definition

function totalLengthOverload(x:any[],y:any[]):number
function totalLengthOverload(x:string,y:string):number
function totalLengthOverload(x:(string|any[]),y:(string|any[])):number{
 	var total:number = x.length+y.length;                //Since string and any[] both are having the length property  
  										                 // the code will work.. infact it will give some of the common methods	
   // as suggestions, but if we access any member which is not present for any one type, typescript will give error. To avoid that, 		
 	
 	if(x instanceof Array){     //This is called type guard syntax -  which checks the type of param, and do differnt things based on type
 		x.push("abc");
 	}
    if(x instanceof String){
 		x.substr(1);	
 	}
    return total;    
 }

//Big benefit of the ts is to define your own custom type - 3 ways
//1)Interface  - they are used only for compile type check only.. No effect on run time - So you wont be able to see in app.js
// Way to tell ts about the type, they will be removed at run time
//So they dont enforce the values at run time.
interface toDo{
	name:string;
	completed?:boolean;   // ? - Not every toDo requires completed property.. but if it does, it should be boolean

}
var td:toDo={name:'rushi'}; //Error  - without ? after completed

interface ITodoservice{
	add(td:toDo):toDo;
	delete(id:number):void;   //Return type void
	getAll():toDo[];
	gettodo(id:number):toDo;
}

interface jQuery{
	(selector:string):HTMLElement;
	version:number
}
var $=<jQuery>function(selector){          //Casting- We are telling ts that irrespective of the return type of function
	//find DOM element					// I know for sure that its jQuery so cast it to jQuery type					
}
$.version=1.12;
var element=$('#container');

//extending the interface
interface jQuery{
	//here you can add the extention as per your need
	//rather than overwriting, it will append this new interface to the old one
}

//2)enums 

enum ToDoState{
	New = 1, 	//Remener the end is , and center is =, not colon.. also there s no () after the enum name
	Active = 2,
	Complete = 3,
	Deleted = 4
}
interface TODO{
	name:string;        //Remener the end is ; and not comma.. also there s no () after the interface name
	state:ToDoState;
}
var var1:TODO={
	name:'task1',
	state:ToDoState.New
}

function del(abc:TODO) {
	if(abc.state!=ToDoState.New){
		console.log("Not new");
	}

}

//Anonymous type - instead of defining whole new interface just for one property, define it inline. exp.
var ss : {name : string}; //type will be an abject with name as string property
//ss={age:41}; Error - doesnt have name property
///function totalLengthOverload(x:(string|any[]),y:(string|any[])):number can be written as
//function totalLengthOverload(x:{length:number},y:{length:number}):number

//3)Classes 
//type script doesnt introduce the class keyword, ecmascript 6 does.
// And class keyword , even though inroduced in the javascript, it is just syntactical sugar
//javascript is still prototype based programming with object - Not completely object oriented

//Prototype - 
function ToDoServices(){
	this.todos=[];
}
ToDoServices.prototype.getAll=function(){
	return this.todos;
}
var service=new ToDoServices();
service.getAll();

//class - 
class ToDoServices1{
	todos:TODO[] = [];   // type and values
	constructor(tds:TODO[]){
		this.todos=tds;
	}
	//we can combine all these lines by using private keyword, which defines and initializes at the same time
	/*constructor(private todos:TODO[]){

	}*/
	getAll(){
		return this.todos;
	}
}

//static property - Just add static keyword at the time of defining the property - unique value across all instances
class staticClass{
	static a:number=0;
	constructor(b:number){
		staticClass.a=b    //Access via	 ClassName.property  - Same goes for method as well
	}
	static getNext(){		
		return staticClass.a+=1;
	}
	getAll(){
		var newId=staticClass.getNext(); //Access via	 ClassName.methodName  - Same goes for method as well
	}
}

//getter and setter method - accessor - note that they can be applied to object literal as well.. but lets apply it to class here
class smartTodo{
	name:string;
	_state:ToDoState;

	constructor(b:ToDoState){
		this._state=b;
	}
	get getState(){                   //Notice the get and set methods,
		return this._state;
	}
	set setState(newState:ToDoState){
		if(newState==ToDoState.Complete){
			var canBeCompleted=this.getState==ToDoState.Active ||     // which we are using here
			this.getState ==ToDoState.Deleted;

			if(!canBeCompleted){
				throw "must be active or deleted to be marked completed";
				
			}	
		}
		this._state=newState;
	}
	method1(){
		console.log("This is the parent class");
	}
}
//Inheritence
class completeSmartToDo extends smartTodo{
//Constructor - In other languages, you ll have to define the constructor for the derived class, 
// not for javascript
//so, new completeSmartToDo(ToDoState.New) is valid without defining the constructor for completeSmartToDo
//However, lets do it for this case

//IMPORTANT POINTS - If you define the constructor on the derived class, you MUST call the construcor of the base class
//Using super keyword
	constructor(){
		super(ToDoState.Complete);   //super to call the construcor of the parent class

	}
	//override the method by using the same signature
	method1(){
		super.method1();           //super to use the parent class method    
		console.log("This is  the child class");
	}

}
//Abstact classes - inheritence - only suppported by TypeScript
abstract class abbie{
	constructor(private newState:ToDoState){

	}
	abstract canChange(ab:TODO):boolean; //Abstact method - So No Implementation - Child classes MUST implement this method
}
class baby extends abbie{
	constructor(){
		super(ToDoState.New)
	}
	//super.canChange(); will give error as there s no implementtation for canChange in the parent class
	canChange(ab:TODO):boolean{
		return true;
	}
}

///Access modifiers - controlling visibility
//they can be applied to any object in the class
//to methods, to constructor params - to initialize the property and assign value at the same time
// IMP -  even to getters and setters- Although they both must have the same access modifier
//By default - Public
//Javascript doesnnt support the private and protected members - So how come type script does ?
//well it doesnt ..  Atleast not on runtime
//Its only compile time validation - So if you try to use private members, it will cry at compile time- Not at run time though
//Private members wont be listed in the autocomplete list and will show error of try to use them
//Still if you do, doesnt matter

//Implementing interface to class
//class abc implements ITodoservice - Here all the methods of the interface should be implemented in the class abc
//class abc implements interface1, interface2, interface3 --- multiple interface can be implemented
//advantage - once you implement the interface, now if the class methods are changed, even a bit in terms of defintion, then 
// ts will throw error

