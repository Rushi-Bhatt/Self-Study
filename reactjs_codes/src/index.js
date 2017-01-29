import React from 'react'
import {render} from 'react-dom'
import {skidaycount} from './components/SkiDayCount'
import {skidaylist} from './components/SkiDayList'
import {App} from './components/App'
import {whoops404} from './components/whoops404'
import {Router,Route,hashHistory} from 'react-router'
import Member from "./components/Member"
import MemberList from "./components/MemberList"


window.React = React
/*//1)Using props

//here if you dont mention the properties for skidaycount, the getDefaultProps() function will be called
render(
//	<skidaycount total={50} powder={20} backcountry={10} days="days" goal={100}	/>
//	document.getElementById('react-container')

	<skidaylist days={
		[
			{
				resort:"A1 resort",
				date:new Date("1/2/2016"),
				powder:true,
				backcountry:false
			},
			{
				resort:"B1 reso	rt",
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
	}	/>
	document.getElementById('react-container')	
)
*/

//2)Using states
render(
	/*<App />*/  
	//lets incorporate the routes instead of just using the App component
	<Router history={hashHistory}>
		<Route path="/" component={App}>
		<Route path="*" component={whoops404}>
		<Route path="list-days" component={App}>
		<Route path="add-day" component={App}>       //Dont put / before the path name, its automattically understood..just write the name

	</Router>,

	/*  Member Component */
/*	<Member admin={true}
			name="Rushi Bhatt"
			email="rbhatt@ncsu.edu"
			thumbnail="https://media.licdn.com/mpr/mpr/shrinknp_200_200/AAEAAQAAAAAAAAgmAAAAJDQ1MzdhZTc1LTUyMzktNDA2MS1iZjQzLWRmOGI0YzEyN2FhMQ.jpg"	
			makeAdmin = ({email}=> console.log(email)) />,*/

	/*  instead of single member, lets render the member list */
	<MemberList	/>	
	document.getElementById('react-container')
)