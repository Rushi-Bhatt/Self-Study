var React = require("react");

//SubComponent
var AptList = React.createClass({

	handleDelete: function(){
		this.props.onDelete(this.props.whichItem);
	},
	toggleDisplay:function(){
		this.props.onToggle();
	},
	onSubmitForm:function(e){
		e.preventDefault();
		var formdata = {
			fname: this.refs.fname.value,
			lname : this.refs.lname.value
		}
		this.props.onFormSubmit(formdata);
	},
	render:function(){
		var displayBody = {
			display : this.props.bodyVisible ? "block":"none"
		};

		return(
			<div>
				<div className="header">
					<span onClick={this.toggleDisplay}>Click me to hide/show the body </span>
				</div>
				<div className="body" style={displayBody}>
				<li>
					<span>{this.props.singleItem.fname} {this.props.singleItem.lname}</span>
					<span>{this.props.singleItem.fname} {this.props.singleItem.lname}</span> 
					<button onClick = {this.handleDelete}></button>
				</li>
				<form onSubmit = {this.onSubitForm}>
				<input type="text" ref= "fname" />
				<input type="text" ref="lname" />
				</form>
				</div>
			</div>
		) //return

	}//render method

}); //AptList

module.exports = AptList;