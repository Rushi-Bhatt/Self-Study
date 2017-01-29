import {Component} from 'react'
import FaShield from 'react-icons/lib/fa/shield'

class Member extends Component{
	const {name,email,thumbnail,admin,makeAdmin} = this.props
	render(){
		<div className="member">
			<h1>{name} {(admin)? <FaShield /> : null}</h1>
			<img src={thumbnail} />
			<a onClick={makeAdmin}>MakeAdmin</a>
			<p><a href={'mailto:${email}'}</p>
		</div>

	}
}	
export default Member