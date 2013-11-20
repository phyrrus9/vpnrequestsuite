<html>
	<head>
		<title>Submit Request</title>
	</head>

	<body>
		<?php
			passthru("/requests/bin/user_request " . $_POST['user'] . " " . $_POST['pass'] . " " . $_POST['req'], $ret);
		?>
	</body>
</html>
