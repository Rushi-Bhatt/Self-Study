import Terrain from 'react-icons/lib/md/terrain'
import SnowFlake from 'react-icons/lib/ti/weather-snow'
import Calendar from 'react-icons/lib/fa/calendar'
import skidayrow from './SkiDayRow'
import {PropTypes} from 'react'

export const skidaylist=({days})=>{
	
	return (
	<div className="ski-day-list">
	<table>
		<thead>
			<tr>
				<th>Date</th>
				<th>Resource</th>
				<th>Powder</th>
				<th>Backcountry</th>
			</tr>
		</thead>
		<tbody>
			{days.map((day,i)=>
				<SkiDayRow key={i}
						   resort={day.resort}
						   date={day.date}
						   powder={day.powder}
						   backcountry={day.backcountry} />		   //here instead of setting all the properties, we can use {...day}
			)}													  //spread operator that will set all the properties, key we need to set explicitly		
		</tbody>

	</table>
	</div>
	)
}
//Custom validation using function
skidaylist.propTypes={
	days: function(props){
		if(!Array.isArray(props.days)){
			return new Error("skidaylist should be an array")
		}
		else if(!props.days.length){
			return new Error("skidaylist should have atleast 1 element")
		}
		else{
			return null
		}

	}      // PropTypes.array if custom validation is not required then  
}