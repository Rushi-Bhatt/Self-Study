import {createClass} from 'react'
import {skidaycount} from './components/SkiDayCount'
import {skidaylist} from './components/SkiDayList'
import {Component} from 'react'
import {AppDayForm} from './components/AppDayForm'
import {Menu} from './components/Menu'

/*//1) States Using the createClass way
export const App=createClass({
	getInitialState(){
		return {
				allSkiDays:
				[
					{
						resort:"A1 resort",
						date:new Date("1/2/2016"),
						powder:true,
						backcountry:false
					},
					{
						resort:"B1 resort",
						date:new Date("1/3/2016"),
						powder:false,
						backcountry:false
					},
					{
						resort:"C1 resort",
						date:new Date("1/4/2016"),
						powder:false,
						backcountry:true
					},
				]
		}
	},
	countDays(filter_var){
		return this.state.allSkiDays.filter(function(day){
			if(filter_var){
				return day[filter_var]
			}
			else{
				return day
			}
		}).length
	},
	render(){
		return (
			<div className="app">
				{this.state.allSkiDays[0]["resort"]}      //should give A1 resort 
				<skidaylist days=this.state.allSkiDays />  //here instead of passing 'days' array as props, 
														   //I can set the prop as allSkiDays state
				<skidaycount total={this.countDays()} 
							 powder={this.countDays("powder")} 
							 backcountry={this.countDays("backcountry")} />		   
			</div>
		)
	}

})

*/

//2)States using the ES6 class syntax
//Constructor instead of getInittialState method
export class App extends Component {
	constructor(props){
		super(props)
		this.state={
			allSkiDays:
				[
					{
						resort:"A1 resort",
						date:new Date("1/2/2016"),
						powder:true,
						backcountry:false
					},
					{
						resort:"B1 resort",
						date:new Date("1/3/2016"),
						powder:false,
						backcountry:false
					},
					{
						resort:"C1 resort",
						date:new Date("1/4/2016"),
						powder:false,
						backcountry:true
					},
				]
		}
		this.addDay=this.addDay.bind(this)  //bind the function 
	}
	addDay(newDay){
		//function to add the new day to the allSkiDay data
		this.setState({ 
			allSkiDays:[
			...this.state.allSkiDays,
			newDay
			]
		})
	}
	countDays(filter_var){
		return this.state.allSkiDays.filter(function(day){
			if(filter_var){
				return day[filter_var]
			}
			else{
				return day
			}
		}).length
	}
	render(){
		return (
			<div className="app">
				<Menu />
				{this.state.allSkiDays[0]["resort"]}      //should give A1 resort 
				
				{(this.props.location.pathname==="/")? 
							 <skidaycount total={this.countDays()} 
							 powder={this.countDays("powder")} 
							 backcountry={this.countDays("backcountry")} /> :

							 {this.props.location.pathname==="/add-day"}? <AddDayForm onNewDay = {this.addDay} /> : 
							 <skidaylist days=this.state.allSkiDays />  //here instead of passing 'days' array as props, 
														                //I can set the prop as allSkiDays state
				}			   
			</div>
		)
	}

}