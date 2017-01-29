import Terrain from 'react-icons/lib/md/terrain'
import SnowFlake from 'react-icons/lib/ti/weather-snow'
import Calendar from 'react-icons/lib/fa/calendar'
import {PropTypes} from 'react'

//here in getMonth wehave used +1 as its 0 based index so January is 0, we want it 1
export const skidayrow=({resort,date,powder,backcountry})=>(

<tr>
	<td>
		/*{date.getMonth()+1}/{date.getDate()}/{date.getFullYear()}*/
		{date}  //For simplicity, lets keep the date as string only
	</td>
	<td>
		{resort}
	</td>
	<td>
		{(powder) ? <SnowFlake /> : null }
	</td>
	<td>
		{(backcountry) ? <Terrain /> : null }
	</td>
</tr>

)

skidayrow.propTypes={
	resort:PropTypes.string.isRequired,
	/*date:PropTypes.instanceOf(Date).isRequired,*/
	date:PropTypes.string.isRequired,
	powder:PropTypes.bool,
	backcountry:PropTypes.bool
}