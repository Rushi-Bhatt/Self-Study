import {Component } from 'react'
import fetch from 'isomorphic-fetch'   //IMP - To fetch the data from API
import member from "./components/Member"

class MemberList extends Component{
	constructor(props){
		super(props)
		this.state={
			members:[
				{
					name:"ABC",
					email:"abc@gmail.com",
					thumbnail:"shbdvdbn"	
				},
				{
					name:"DEF",
					email:"def@gmail.com",
					thumbnail:"shbdvdbn"	
				},
				{
					name:"GHI",
					email:"ghi@gmail.com",
					thumbnail:"shbdvdbn"	
				},
			]
		}
	}	

	/* fetch("api url")
		.then(response => response.json)
		.then(json => json.results) ///results is the key  of data -- depends on the data
		.then(members => this.setState({
			members:members
		}))
	   */  //This is how to dnamically mount the data to the members

	   
	render(){
		const {members}=this.state
		return(
			<div className="member-list">
				<h1>Society Members</h1>
				{members.map(
					(data,i)=> 
					<Member key={i}
							onClick= {(email) => console.log(email)}
							{...data} />

				)}

			</div>
		)	
	}
}
export default MemberList