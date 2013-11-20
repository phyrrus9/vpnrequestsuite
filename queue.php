<html>
	<head>
		<title>Active Queue</title>
	</head>

	<body>
		<?php
			passthru("/requests/bin/queue", $ret);
		?>
	</body>
</html>
