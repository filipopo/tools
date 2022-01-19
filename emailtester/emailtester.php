<?php

echo "<!DOCTYPE html>
<html lang='en'>
<head>
<title>emailtester</title>
</head>
<body>
";

if (count($_POST)) {
	$headers = "From: " . $_POST["from"] . "\r\n";
	if ($_POST["cc"])
		$headers .= "Cc: " . $_POST["cc"];
		if ($_POST["bcc"])
			$headers .= "\r\n";
	if ($_POST["bcc"])
		$headers .= "Bcc: " . $_POST["bcc"];

	for ($x = 1; $x <= $_POST["times"]; $x++) {
		$sent = mail($_POST["to"], $_POST["subject"], $_POST["message"], $headers);
		echo $sent ? "Sent: $x time<br>\n" : "Failed to send $x time<br>\n";
	}
} else {
echo "<form method='POST'>
From:<br>
<input type='email' name='from' required><br>
To(comma separated):<br>
<input type='text' name='to' required><br>
Subject:<br>
<input type='text' name='subject' required><br>
Message:<br>
<input type='text' name='message' required><br>
Cc(comma separated):<br>
<input type='text' name='cc'><br>
Bcc(comma separated):<br>
<input type='text' name='bcc'><br>
Times:<br>
<input type='number' min='1' value='1' name='times'><br>
<br>
<input type='submit' value='Send'>
</form>
";
}

echo "</body>
</html>";

?>
