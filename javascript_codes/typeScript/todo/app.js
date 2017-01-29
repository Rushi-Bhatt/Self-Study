var __extends = (this && this.__extends) || function (d, b) {
    for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p];
    function __() { this.constructor = d; }
    d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
};
var abc = "pickup";
var a = "abc";
var b = "bcsd";
var c = "anana";
//1)Optimal parameters
//Give default values to parameter in the type script, so rather than ignoring the values, javascript will check if the value
//is passed..If not, then it will consider the default value, else the passed value
function timer(initial, final1, interval) {
    if (interval === void 0) { interval = 1; }
    console.log(initial);
    console.log(final1);
    console.log(interval);
}
timer(10, 0);
//2)Template Strings
var container = document.getElementById("#container");
var todo = {
    id: 123,
    name: "Pick up ben",
    completed: true
};
var displayName = "ToDo #" + todo.id;
//3)let and const keyword
for (var x = 0; x < 5; x++) {
    var count = x;
    var c1 = x;
}
//console.log(count);  this will give error as we have used let, so count is not accessible outside the for loop 
//4) for of syntax that lets you loop over the elements of array without having to use the syntax
var array = ["pickup ben", "pay the bill", "eat and sleep"];
for (var index in array) {
    var task = array[index];
    console.log(index + " : " + task);
}
for (var _i = 0, array_1 = array; _i < array_1.length; _i++) {
    var task = array_1[_i];
    //var task=array[index];         //Dont need this now
    console.log("" + task);
}
//5) Lambda expression - Arrow function
var filtered = [1, 2, 3].filter(function (x) { return x > 2; });
console.log(filtered);
//6)Destructuring 
var array1 = [123, "pickup", true];
var id1 = array1[0], task1 = array1[1], completed1 = array1[2];
var _a = [124, "eat", true], id2 = _a[0], task2 = _a[1], completed2 = _a[2];
console.log(id2);
//same can be used for .. [a,b]=[b,a] - interchanging the values
//same can be used for objects as well where the values are compared with the keys
var xyz = {
    x: 123,
    w: true,
    y: "sleep",
    z: false
};
var x = xyz.x, y = xyz.y, z = xyz.z;
console.log(x, y, z);
//same works for return value - very important
// you can change the variable name as well, by specifying it with : sign
function temp1() {
    var abcd = {
        a: 123,
        b: true,
        c: "sleep",
        d: false
    };
    return abcd;
}
var _b = temp1(), A = _b.a, B = _b.b, C = _b.c, D = _b.d;
console.log(A, B, C, D);
//7)Spread operator // function that takes any number of arguments
function calculate(action) {
    var values = [];
    for (var _i = 1; _i < arguments.length; _i++) {
        values[_i - 1] = arguments[_i];
    }
    var total = 0;
    for (var _a = 0, values_1 = values; _a < values_1.length; _a++) {
        var value = values_1[_a];
        switch (action) {
            case 'add':
                total += value;
                break;
            case 'sub':
                total -= value;
                break;
        }
    }
    return total;
}
console.log(calculate('add', 1, 2, 5, 4, 6));
//another use is to concat two arrays directly  - Very important
var ar1 = [1, 2, 3];
var ar2 = [4, 5,  /*Insert that array here*/, 6, 7];
ar2 = [4, 5].concat(ar1, [6, 7]);
console.log(ar2);
ar2.push.apply(ar2, ar1); //Concate two arrays
console.log(ar2);
//type fundamentals: 1)null/undefined 2)string, number, boolean - immutables 3)objects- array, functions, date, regex etc.
//type inference - ability of type script to detect the type of object on the fly.. so it will sense the type of name as string
// since we assigned a value of string to the name. Thefore , when we assign the value as 1, it will give error
var animal = {
    name: "frodo",
    age: calculateAge(2010),
    speak: function () {
        console.log('woof!');
    }
};
//animal.name=1;   //ts will give error as 1 is number, not string
//same can be true for function return type
//ts will detect the return type of calculateaAge as number, because the Date.now is of type number
function calculateAge(birthyear) {
    return Date.now() - birthyear;
}
//When the ts doesnt recognize the type of any expression, it sets it as 'any' - most dynamic loose type- same as javascript
///for exp.. here the return type of tlength is 'any'
function tlength(x, y) {
    return x.length + y.length; //if y.len, then also it wont give any error - coz it doesnt know the type
}
//So to avoid this, we need to provide the type of each object - So that type script can check the sentence for ay error
function totalLength(x, y) {
    var total = x.length + y.length; //any[] - array of objects of any type - since we only are considering 
    return total; //length, we dont care about the type
}
// Unioun type - | operator 
function totalLengthWithUnioun(x, y) {
    var total = x.length + y.length; //Since string and any[] both are having the length property  
    // the code will work.. infact it will give some of the common methods	
    // as suggestions, but if we access any member which is not present for any one type, typescript will give error. To avoid that, 		
    if (x instanceof Array) {
        x.push("abc");
    }
    if (x instanceof String) {
        x.substr(1);
    }
    return total;
}
function totalLengthOverload(x, y) {
    var total = x.length + y.length; //Since string and any[] both are having the length property  
    // the code will work.. infact it will give some of the common methods	
    // as suggestions, but if we access any member which is not present for any one type, typescript will give error. To avoid that, 		
    if (x instanceof Array) {
        x.push("abc");
    }
    if (x instanceof String) {
        x.substr(1);
    }
    return total;
}
var td = { name: 'rushi' }; //Error  - without ? after completed
var $ = function (selector) {
    //find DOM element					// I know for sure that its jQuery so cast it to jQuery type					
};
$.version = 1.12;
var element = $('#container');
//2)enums 
var ToDoState;
(function (ToDoState) {
    ToDoState[ToDoState["New"] = 1] = "New";
    ToDoState[ToDoState["Active"] = 2] = "Active";
    ToDoState[ToDoState["Complete"] = 3] = "Complete";
    ToDoState[ToDoState["Deleted"] = 4] = "Deleted";
})(ToDoState || (ToDoState = {}));
var var1 = {
    name: 'task1',
    state: ToDoState.New
};
function del(abc) {
    if (abc.state != ToDoState.New) {
        console.log("Not new");
    }
}
//Anonymous type - instead of defining whole new interface just for one property, define it inline. exp.
var ss; //type will be an abject with name as string property
//ss={age:41}; Error - doesnt have name property
///function totalLengthOverload(x:(string|any[]),y:(string|any[])):number can be written as
//function totalLengthOverload(x:{length:number},y:{length:number}):number
//3)Classes 
//type script doesnt introduce the class keyword, ecmascript 6 does.
// And class keyword , even though inroduced in the javascript, it is just syntactical sugar
//javascript is still prototype based programming with object - Not completely object oriented
//Prototype - 
function ToDoServices() {
    this.todos = [];
}
ToDoServices.prototype.getAll = function () {
    return this.todos;
};
var service = new ToDoServices();
service.getAll();
//class - 
var ToDoServices1 = (function () {
    function ToDoServices1(tds) {
        this.todos = []; // type and values
        this.todos = tds;
    }
    //we can combine all these lines by using private keyword, which defines and initializes at the same time
    /*constructor(private todos:TODO[]){

    }*/
    ToDoServices1.prototype.getAll = function () {
        return this.todos;
    };
    return ToDoServices1;
}());
//static property - Just add static keyword at the time of defining the property - unique value across all instances
var staticClass = (function () {
    function staticClass(b) {
        staticClass.a = b; //Access via	 ClassName.property  - Same goes for method as well
    }
    staticClass.getNext = function () {
        return staticClass.a += 1;
    };
    staticClass.prototype.getAll = function () {
        var newId = staticClass.getNext(); //Access via	 ClassName.methodName  - Same goes for method as well
    };
    staticClass.a = 0;
    return staticClass;
}());
//getter and setter method - accessor - note that they can be applied to object literal as well.. but lets apply it to class here
var smartTodo = (function () {
    function smartTodo(b) {
        this._state = b;
    }
    Object.defineProperty(smartTodo.prototype, "getState", {
        get: function () {
            return this._state;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(smartTodo.prototype, "setState", {
        set: function (newState) {
            if (newState == ToDoState.Complete) {
                var canBeCompleted = this.getState == ToDoState.Active ||
                    this.getState == ToDoState.Deleted;
                if (!canBeCompleted) {
                    throw "must be active or deleted to be marked completed";
                }
            }
            this._state = newState;
        },
        enumerable: true,
        configurable: true
    });
    smartTodo.prototype.method1 = function () {
        console.log("This is the parent class");
    };
    return smartTodo;
}());
//Inheritence
var completeSmartToDo = (function (_super) {
    __extends(completeSmartToDo, _super);
    //Constructor - In other languages, you ll have to define the constructor for the derived class, 
    // not for javascript
    //so, new completeSmartToDo(ToDoState.New) is valid without defining the constructor for completeSmartToDo
    //However, lets do it for this case
    //IMPORTANT POINTS - If you define the constructor on the derived class, you MUST call the construcor of the base class
    //Using super keyword
    function completeSmartToDo() {
        _super.call(this, ToDoState.Complete); //super to call the construcor of the parent class
    }
    //override the method by using the same signature
    completeSmartToDo.prototype.method1 = function () {
        _super.prototype.method1.call(this); //super to use the parent class method    
        console.log("This is  the child class");
    };
    return completeSmartToDo;
}(smartTodo));
//Abstact classes - inheritence - only suppported by TypeScript
var abbie = (function () {
    function abbie(newState) {
        this.newState = newState;
    }
    return abbie;
}());
var baby = (function (_super) {
    __extends(baby, _super);
    function baby() {
        _super.call(this, ToDoState.New);
    }
    //super.canChange(); will give error as there s no implementtation for canChange in the parent class
    baby.prototype.canChange = function (ab) {
        return true;
    };
    return baby;
}(abbie));
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
