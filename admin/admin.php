<?php
	session_start();
	if ($_SESSION['admin'] != 1)
	{
		header('Location: login.php');
	}
?>
<html>
	<head>
		<title>Request Administrator interface</title>
	</head>

	<nav>
		<a href="admin.php?action=list">List Users</a> | <a href="admin.php?action=online">Online Users</a> | <a href="admin.php?action=queue">Queue</a> |
		<a href="admin.php?action=expire">Expire Users</a> | <a href="admin.php?action=unexpire">Unexpire Users</a> |
		<a href="admin.php?action=accept">Accept Users</a> | <a href="admin.php?action=tickets">View Tickets</a> | <a href="login.php">Log Out</a>
	</nav>

	<body>
		<?php
			switch($_GET['action'])
			{
				case "list":
					echo "<pre>";
					passthru("/requests/bin/userlist", $ret);
					echo "</pre>";
					break;
				case "online":
					echo "<u>Currently online users</u><br />";
					echo "<pre>";
					passthru("last | grep ppp | grep still", $ret);
					echo "</pre>";
					break;
				case "tickets":
					echo "<pre>";
					passthru("/requests/bin/user_request", $ret);
					echo "</pre>";
					break;
				case "queue":
					passthru("/requests/bin/queue", $ret);
					break;
				case "expire":
					?>
					<form name="input" action="do.php?action=expire" method="post">
						Usernames: <input type="text" name="expirelist">
						<input type="submit" value="Expire">
					</form>
					Please type all usernames, separated by spaces
					<?php
					break;
				case "unexpire":
					?>
					<form name="input" action="do.php?action=unexpire" method="post">
						Usernames: <input type="text" name="unexpirelist">
						<input type="submit" value="Unexpire">
					</form>
					Please type all usernames, separated by spaces
					<?php
					break;
				case "accept":
					?>
					<form name="input" action="do.php?action=accept" method="post">
						Usernames: <input type="text" name="acceptlist">
						<input type="submit" value="Accept">
					</form>
					Please type all usernames, separated by spaces
					<?php
					break;
				default:
					?>
					Welcome to the admin panel!
					<?php
			}
		?>
	</body>
</html>
