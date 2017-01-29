import React from 'react'
import '../stylesheets/ui.scss'
import Terrain from 'react-icons/lib/md/terrain'
import SnowFlake from 'react-icons/lib/ti/weather-snow'
import Calendar from 'react-icons/lib/fa/calendar'

//1)Using the createClass method
/*export const skidaycount = React.createClass({
	//property types, .isRequired - required true else error
	propTypes:{
		total:React.PropTypes.number.isRequired,
		powder:React.PropTypes.number,
		backcountry:React.PropTypes.number,
	},

	//Default props
	getDefaultProps(){
		return {
			total:50,
			powder:50,
			backcountry:15,
			goal:100	
		}
	},
	percentToDecimal(decimal){
		return ((decimal*100)+'%')
	},
	calProgress(total,goal){
		return this.percentToDecimal(total/goal)
	},
	render(){
		return (
			<div className="ski-day-count">
				<div className="total-days">
				<span>{this.props.total}</span>
				<span>days</span>
				</div>
				<div className="powder-days">
				span>{this.props.powder}</span>
				<span>days</span>
				</div>
				<div className="backcountry-days">
				<span>{this.props.backcountry}</span>
				<span>days</span>
				</div>
				<div>
				<span>{this.props.goal}</span>
				<span>days</span>
				<span>{this.calProgress(this.props.total,this.props.goal)}</span>
				</div>
			</div>
		)
	}
})*/

//2)Using the  ES6 class syntax
//So now lets code the same thing using the class syntax of ES6
//here you can also use import {Component} from 'react ' and then you dont have to use React.Component, you can directly use Component
/*export class skidaycount extends React.Component{       //no need of const keyword and () 
	percentToDecimal(decimal){
		return ((decimal*100)+'%')
	}   //no need to separate methods with ,
	calProgress(total,goal){
		return this.percentToDecimal(total/goal)
	}
	render(){
		return (
			<div className="ski-day-count">
				<div className="total-days">
				<span>{this.props.total}</span>
				<span>days</span>
				</div>
				<div className="powder-days">
				span>{this.props.powder}</span>
				<span>days</span>
				</div>
				<div className="backcountry-days">
				<span>{this.props.backcountry}</span>
				<span>days</span>
				</div>
				<div>
				<span>{this.props.goal}</span>
				<span>days</span>
				<span>{this.calProgress(this.props.total,this.props.goal)}</span>
				</div>
			</div>
		)
	}
}
//default properties
skidaycount.defaultProps= {
			total:50,
			powder:50,
			backcountry:15,
			goal:75
}

//property types, .isRequired - required true else error
skidaycount.propTypes= {
		total:React.PropTypes.number.isRequired,
		powder:React.PropTypes.number,
		backcountry:React.PropTypes.number,
}
*/

//3)Using the stateless function 
const percentToDecimal=(decimal)=>{
	return ((decimal*100)+'%')
}   
const calProgress=(total,goal)=>{
	return percentToDecimal(total/goal)
}
export const skidaycount =(props)=> (          // no need of {} and render method, ypu can also use destructuring and instead of
			<div className="ski-day-count">	   //props, we can only pass {total,powder,backcountry,goal}.. so no need to use
				<div className="total-days">   //props.total etc.. we can directly use total	
				<span>{props.total}</span>	   // IMP : Another way to set default	
				<Calendar />                   //skidaycounnt= ({total=70, powder=20, backcountry=10,goal=100})=>(...)
				<span>days</span>
				</div>
				<div className="powder-days">
				span>{props.powder}</span>
				<SnowFlake />
				<span>days</span>
				</div>
				<div className="backcountry-days">
				<span>{props.backcountry}</span>
				<Terrain />
				<span>days</span>
				</div>
				<div>
				<span>{props.goal}</span>
				<span>days</span>
				<span>{calProgress(props.total,props.goal)}</span>
				</div>
			</div>
)
//default properties-- or you can directly set is as parameters , explained above 
skidaycount.defaultProps= {
			total:50,
			powder:50,
			backcountry:15,
			goal:75
}

//property types, .isRequired - required true else error
skidaycount.propTypes= {
		total:React.PropTypes.number.isRequired,
		powder:React.PropTypes.number,
		backcountry:React.PropTypes.number,
		goal:React.PropTypes.number,
}