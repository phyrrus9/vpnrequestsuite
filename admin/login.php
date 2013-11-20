<?php
	session_start();
	if ($_SESSION['admin'] == 1)
	{
		$_SESSION['admin'] = 0;
	}
	{
		echo "<hidden>";
		system("/requests/bin/admin " . $_POST['uname'] . " " . $_POST['passw'], $ret);
		$_SESSION['admin'] = $ret;
		echo "</hidden>";
	}

?>
<html>
	<head>
		<title>Administrator Login</title>
	</head>

	<body>
		<?php
			if ($_SESSION['admin'] != 1)
			{
			?>
                                <form name="input" action="login.php" method="post">
                                	Username: <input type="text" name="uname">
                                	Password: <input type="password" name="passw">
                                        <input type="submit" value="Log in">
                                </form>
			<?php
			}

		?>
		<a href="admin.php">Admin Panel</a>
	</body>
</html>
