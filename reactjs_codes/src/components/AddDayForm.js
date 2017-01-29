import {Component,PropTypes} from 'react'

//IMP
//see the use of htmlFor instead of for, because for us javascript keyword
//defaultValue and defaultChecked - in input tags

//1)Refs using the class component - ES6
/*export class AddDayForm extends Component {

	constructor(props){
		super(props)
		this.submit=this.submit.bind(this)  //We need to bind this. So when we create a custom method and we need to use this 
											//for this.submit or anything else, we need to have 'this' accessible.
	}
	submit(e){

		e.preventDefault(); //to prevent the actual form submission routine, which was to clear out the form
		console.log("resort",this.ref.resort.value)
		console.log("date",this.ref.date.value)
		console.log("powder",this.ref.powder.checked)
		console.log("backcountry",this.ref.backcountry.checked )
	}

	render(){
		const {resort,date,powder,backcountry} = this.props //setting the values to default which will be used in the input tags
		return (
			<form onsubmit={this.submit}  className="add-day-form">
				<label htmlFor="resort">Resort Name</lebel>
				<input id="resort" type="text" defaultValue = {resort} ref="resort" required />

				<label htmlFor="date">Date</lebel>
				<input id="date" type="date" defaultValue = {date} ref="date" required />
				
				<label htmlFor="powder">Powder</lebel>
				<input id="powder" type="checkbox" defaultChecked = {powder} ref="powder"  required />
				
				<label htmlFor="backcountry">Backcountry</lebel>
				<input id="backcountry" type="checkbox" defaultChecked = {backcountry}  ref="backcountry"  required />
				<button>Add Day</button>
			</form>
		)
	}
}

AddDayForm.defaultProps= {
	resort:"Default Resort",
	date:"1/1/2011",
	powder:false,
	backcountry:false
}

AddDayForm.propTypes= {
	resort:PropTypes.string.isRequired,
	date:PropTypes.string.isRequired,
	powder:PropTypes.bool.isRequired,
	backcountry:PropTypes.bool.isRequired
}*/

const tahoeResorts = [
"E1 resort",
"F1 resort",
"G1 resort",
"H1 resort",
"I1 resort",
"J1 resort",
"K1 resort",
"L1 resort",
]

export const AutoComplete extends Component{
	get value(){
		return this.refs.inputResort.value
	}
	set value(input){
		this.refs.inputResort.value=input
	}
	render(){
		return(
			<div>	
				<input ref = "inputResort" type="text" list="tahoe-resorts" />  //see the list field..it should be same as datalist id
				<datalist id="tahoe-resorts">
					{this.props.options.map(
						(opt,i)=> <option key={i}>{opt}</option>
					)}
				</datalist>	
			</div>
		)
	}
}
//2) refs using the stateless function -
export const AddDayForm = ({resort,date,powder,backcountry,onNewDay}) => {

	let _resort,_powder,_backcountry,_date
	const submit = (e)=> {
		e.preventDefault(); //to prevent the actual form submission routine, which was to clear out the form
		onNewDay({
			resort:_resort.value,
			date:_date.value,
			powder:_powder.checked,
			backcountry:_backcountry.checked
		})
		_resort.value=" "
		_date.value=" "
		_powder.checked=false
		_backcountry.checked=false

/*		console.log("resort",_resort.value)
		console.log("date",_date.value)
		console.log("powder",_powder.checked)
		console.log("backcountry",_backcountry.checked )*/
	}

	return (
			<form onsubmit={submit}  className="add-day-form">
				<label htmlFor="resort">Resort Name</lebel>
				/*<input id="resort" type="text" defaultValue = {resort} ref={input=> _resort=input} required />*/

				<AutoComplete ref={input=> _resort=input} options={tahoeResorts} />

				<label htmlFor="date">Date</lebel>
				<input id="date" type="date" defaultValue = {date} ref={input=> _date=input} required />
				
				<label htmlFor="powder">Powder</lebel>
				<input id="powder" type="checkbox" defaultChecked = {powder} ref={input=> _powder=input}  required />
				
				<label htmlFor="backcountry">Backcountry</lebel>
				<input id="backcountry" type="checkbox" defaultChecked = {backcountry}  ref={input=> _backcountry=input}  required />
				<button>Add Day</button>
			</form>
	)

}