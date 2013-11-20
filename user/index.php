<html>
	<head>
		<title>VPN Request Form</title>
	</head>

	<body>
		<form name="input" action="submit_request.php" method="post">
			Username: <input type="text" name="user"><br />
			Password: <input type="password" name="pass"><br />
			Request: <textarea name="req" rows="10" cols="30">something like: need password set to xxxx,<br />
					need to make a payment, when can you meet,<br />
					No longer need my account
				</textarea>
			<input type="submit" value="Submit">
		</form>
		<sub>
			Note: Please do not include spaces ANYWHERE in these fields.<br />
			&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Doing so wil only cause a failure to add you to the system.
			*Exception* The request field
		</sub>
	</body>
</html>
