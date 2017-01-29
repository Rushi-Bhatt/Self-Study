var fs=require("fs");

//Listing direcory files
var files=fs.readdirSync("./lib");  //list of all the content inside the lib directory in the form of an array- files and hidden files with extensions, directories without
console.log(files);
//readdirsync reads the files synchronously blocking the only thread of node.js
//Only configuration files must be read synchronously before starting the app
//otherwise use asynch call for file read
//like below
fs.readdir("./lib",function(err,files){
	if(err){
		throw err;
	}
	else{
		console.log(files);
	}
	
});
console.log("ReadingDirLists...");
//Every single fs commands have sync and async version

//reading the files - binary , text
//by default reads all files as binary unless proper encoding is passed as an argument in which case it will be read as text
var contents=fs.readFileSync("./lib/Person.js","UTF-8"); 
console.log("Sync Text File:"+contents);
fs.readFile("./lib/Person.js","UTF-8",function(err,contents){
	if(err){
		console.log(err); //throw err kills the process, log doesnt kill it, just makes a log of error
	}
	else{
		console.log("ReadingFiles...");
		console.log("async Text File:"+contents);
	}
	
});

//now lets read it without encoding - will be read as binary - and handles as buffer class
var contents=fs.readFileSync("./lib/Person.js"); 
console.log(contents);

//function to read all the files in the directory
var path=require("path");
fs.readdir("./lib",function(err,files){
	files.forEach(function(fileName){
		var filePath=path.join(__dirname,"lib",fileName);
		var stats = fs.statSync(filePath);     //statSync  - gives the statistics about the file - takes entire filepath as ann argument
		if(stats.isFile()){					//stats.isFile() - If the given file is file and not directory
			fs.readFile(filePath,function(err,contents){
				console.log(` \n\n ${filePath}: \n ${contents}`);
			});
		}	
	});
});

//Writing and appending the files
///writing file - 
var md=`

Sample markdown title
=====================

hi there, 
---------------------
`;
//Lets do it Asyncly
fs.writeFile("sample.md",md.trim(),function(err){   //Syntax - writeFile(filename, content, callbackFunction)
	console.log("File Created Asyncly");
});

//synchronously
fs.writeFileSync("sample1.md",md.trim());
console.log("File created synchronously");


///appending file - 
var appendedContent = `
new contents 
==============
appendedContent==
---------------
`;
//lets do it asyncly
fs.appendFile("sample.md",appendedContent,function(){

});  //Note that there is no need for callbackFunction but one should
console.log("Appended Asyncly");

//synchronously
fs.appendFileSync("sample1.md",appendedContent);  
console.log("Appended syncly");

//Creating directory
//lets do it asyncly
if(fs.exists("Test")){	//existsSync - Check if the file or directory exists
	console.log("Directory/file already there");
}
else{
	fs.mkdir("Test",function(err){
		if(err){
		 	console.log(err);
		}
		else{
			console.log("Directory Created Asyncly");
		}
	});
}

//lets do it synchronously
if(fs.existsSync("Test1")){	//existsSync - Check if the file or directory exists
	console.log("Directory/file already there");
}
else{
fs.mkdirSync("Test1");
console.log("Directory Created synchronously");
}


//Deleting the directory
///  VERY IMP : ERROR IF THE DIR IS NOT EMPTY
//ONLY EMPTY DIRECTORIES CAN BE DELETED, ELSE WILL GIVE ME ERROR

//So To delete the directory, first unllink all the files of that directory and then rmdir
/*fs.readdirSync("./deletethis").forEach(function(fileName){
	fs.unlinkSync("./deletethis/"+fileName);
});

//Asynchly
fs.rmdir("./deletethis",function(err){
	if(err){
		console.log(err);    ///  VERY IMP : ERROR IF THE DIR IS NOT EMPTY
		//ONLY EMPTY DIRECTORIES CAN BE DELETED, ELSE WILL GIVE ME ERROR
	}
	else{
		console.log("Directory has been removed successfully");
	}		
});
*///same can be done synchly
//fs.rmdirSync("./deletethis");



//Renaming/ removing files
//Asynchly
/*fs.rename("./lib/test.txt","./lib/renamed_test.txt",function(err){
	console.log(err);
}); 
*/
// synchronously 
/*fs.renameSync("./lib/test.txt","./lib/ntest.txt");
console.log("Renamed synchronously");*/

fs.rename("./lib/ntest.txt","ntest.txt",function(err){
	console.log("File moved successfully");
});

//Remove the files
//synchronously
//It will automatically throw error since its a sync call
//To manually handle the error in sync call
/*try{
fs.unlinkSync("./lib/delete.txt");		
console.log("File removed synchronously");
}
catch(err){
	console.log(err);	
}

//Asyncly
fs.unlink("./lib/delete1.txt",function(err){
	if(err){
		console.log(err);
	}
	else{
		console.log("File removed asynch");
	}
});

//Renaming and removing the directories
fs.renameSync("./Test","./Test1/Test");
console.log("directory moved");
fs.rename("./rename","./rename1",function(err){
	console.log(err);
});
*/
//Readable file streams

//process stdout and stdin both implement the stream interface
//stdout - writable stream - we send data to it using the write method
//stdin - readable stream - 

//readFile function  - if we read very long file, It will read the entire file first, store it in buffer, and then execute the
//call back function. which may create latency. So insteaf better approach is to use readable continuous data stream

var stream=fs.createReadStream("ntest.txt");
var data=" ";
stream.once("data",function(){		//ONCE - Only happens first time the data event is triggered
	console.log("\n\n\n");
	console.log("Started reading the file...");
	console.log("\n\n\n");
});
stream.on("data",function(chunk){
	data+=chunk;
	console.log(`data - ${chunk.length} | `);
});
stream.on("end",function(){			//"end" is triggered when the stream is ended
	console.log("\n\n\n");
	console.log(`Finished reading the file...${data.length}`);
	console.log("\n\n\n");
});

//writable file streams
var stream=fs.createWriteStream("ntest1.txt");
var data=" nndjfbdndjbjdbfjdbgbdjgdnf,xnnvhjsb sbfjhbfhbf bshfbbf";
stream.write(data); //Write data onto write stream
stream.close();   //Close the write stream
