<html>
	<head>
		<?php
			$fname = $_POST['fname'];
			$lname = $_POST['lname'];
			$user  = $_POST['user'];
			$pass  = $_POST['pass'];
			$conta = $_POST['contact'];

			if (empty($fname) || empty($lname))
				die("Error, go back and fix the name fields");
			if (empty($user) || empty($pass))
				die("Error, go back and fix the user/pass fields");
			if (empty($conta))
				die("Error, we need a method of contact to notify you when you are added!<br />Go back and fix it.");
		?>
		<title>Request sent</title>
	</head>

	<body>
		<?php
			date_default_timezone_set('UTC');
			$added = date(DATE_ATOM);
			$cmd = "/requests/bin/request " . $lname . " " . $fname . " " . $user . " " . $pass . " " . $conta . " " . $added;
			passthru($cmd, $ret);
			if ($ret == 0)
			{
				echo "Feel free to close this window now.<br />We will get ahold of you when your account is ready<br />";
				echo "<br /><br /><br />You may look at the active queue at <a href=\"./queue.php\">this page</a><br />";
			}
		?>
	</body>
</html>
