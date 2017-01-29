//since we are using the browserify, we can use require to import the files/lib/module
var React = require('react')
var ReactDOM= require('react-dom')
var AptList  = require("./AptList")
var _ = require('lodash')  //for deleteMessage method

var MainInterface = React.createClass({
	getInitialState : function(){
		return {
			title:"Appointments",
			show:true,
			orderBy:'fname',
			orderDir:'asc',
			data : []
		}  //return
	}, //getinitialstate

	componentDidMount():function(){
		this.serverRequest = $.get("./data.json",function(result){
			this.setState({
				data : result
			}); //setstate
		}.bind(this)); //serverRequest, we also need to bind 'this' 
	},

	componentWillUnmount:function(){
		this.serverRequest.abort();
	},

	deleteMessage:function(item){
		var allApt = this.state.data;
		var newApt = _.without(allApt,item);
		this.setState({
				data : newApt
			}); //setstate
	},

	toggleVisibility:function(){
		var newVisibilityState = !this.state.show;
		this.setState({
				show : newVisibilityState,
			}); //setstate
	},
	onSubmission:function(newFormData){
		var oldData = this.state.data;
		oldData.push(newFormData);
		this.setState({
			data : oldData	
		});
	},
	render: function(){
		var showTitle = (this.state.show) ? "New":null ;
		var displayList = {
			display: (this.state.show) ? "block":"none" , 
			color:"red"
		}

		var filterData = this.state.data;
		var orderBy = this.state.orderBy;
		var orderDir =this.state.orderDir;

		filterData = _.orderBy(filterData,function(item){
			return item[orderBy].toLowerCase(); //item on which you want to sort
		},orderDir); //orderBy - From Lodash
		
		filterData = filterData.map(function(item,index){
			return( 
				/*<li key={index}>
				<span>{item.fname} {item.lname}</span>
				<span>{this.state.data[index].fname} {this.state.data[index].lname}</span> //IMP - It will show error..Why?
				</li>*/

				//Lets use the subcomponent to render this and lets pass item and index as arguments
				<AptList key={index} 
				         singleItem = {item} 
				         whichItem = {item} 
				         onDelete = {this.deleteMessage}
				         bodyVisible = {this.state.show}
				         onToggle = {this.toggleVisibility} 
				         onSubmitForm = {this.onSubmission} >
			)//return
		}).bind(this);//map ///binding this keyword since it is used outside the return method of render
//when you use this in the render function return method, it has context, but if you use it outside , lets say in map, then this will store the 
//window object, so you again will have to manually bind this with the map function
//using .bind(this)

		return(
			<div className="interface">   //we need this div because return can only return one component, so we need a wrapper around h1 and ul
			<h1>{ showTitle }{this.state.title}</h1>
			<ul>
				<li>Li1</li>
				<li>Li2</li>
				<li>Li3</li>
			</ul>
			</div>
		)
	}  //render
}); //MainInterface

ReactDOM.render(
	<MainInterface />,
	document.getElementById("react-container")
);