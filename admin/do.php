<?php
	session_start();
	if ($_SESSION['admin'] != 1)
	{
		header('Location: login.php');
	}
?>

<?php
	echo "<pre>";
	if ($_GET['action'] == "expire")
	{
		passthru("/requests/bin/expire " . $_POST['expirelist'], $ret);
	}

	if ($_GET['action'] == "unexpire")
	{
		passthru("/requests/bin/unexpire " . $_POST['unexpirelist'], $ret);
	}

	if ($_GET['action'] == "accept")
	{
		passthru("/requests/bin/add " . $_POST['acceptlist'], $ret);
	}
	echo "</pre>";
?>

<br />
<a href="admin.php">Back to Administration Panel</a>
