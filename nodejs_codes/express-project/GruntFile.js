module.exports=function(grunt){
	grunt.initConfig({
		jshint:{  //configuration for jshint task
			files:["*.js","public/*.js","test/*.js","lib/*.js"],
			options:{
				esnext:true,
				globals:{
					jQuery:true
				}
			}

		},

		less:{ //configuration for less task
			production:{
				files:{
					"public/css/style.css":["less/*.less"]  //Covert all less files to css //IMP - Never use  ; after literal
				}
			}

		},

		autoprefixer:{
			single_file:{
				src:"public/css/style.css",
				dest:"public/css/style.css"
			}
		},

		browserify:{	//Bundle up the client side files and dependencies into single js file - efficiently
			client:{	//Set which client side files need to be bundled
				src:["app-client.js"],
				dest:"public/js/bundle.js"
			}
		},

		watch:{ //configure watch task to watch - less files and app-client js files
			css:{
				files:["less/*.less"],  //When any kind of change is made to these files
				tasks:["css"]			//Run this task
			},
			scripts:{
				files:["app-client.js","lib/*.js"],
				tasks:["jshint","browserify"]
			}

		}
	});

	grunt.loadNpmTasks("grunt-contrib-jshint"); //make sure that the jshint is loaded
	grunt.loadNpmTasks("grunt-contrib-less"); //make sure that the less plugin is loaded
	grunt.loadNpmTasks("grunt-autoprefixer"); //make sure that the autoprefixer plugin is loaded
	grunt.loadNpmTasks("grunt-browserify"); //make sure that the browserify plugin is loaded
	grunt.loadNpmTasks("grunt-contrib-watch"); //make sure that the watch plugin is loaded

	grunt.registerTask("css",["less","autoprefixer"]); //setup new css task,  so whenenver that task is called, less and then autoprefixer will be called
	
	grunt.registerTask("js",["browserify"]); //setup js task

	//grunt.registerTask("watch",["watch"]); //DONT DO THIS, we can directly run the grunt watch task, no need to register it

	grunt.registerTask("default",["jshint","css","js"]); //set default task to jshint and css
};