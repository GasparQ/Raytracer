<html>
<head>
	<title>RayTracer || Galeries</title>
	<link href='http://fonts.googleapis.com/css?family=Raleway:100,200,300,400' rel='stylesheet' type='text/css'>
	<style type="text/css">
		body {
			margin: 0 0 0 0 !important;
			padding: 0 0 0 0 !important;
			max-width: 100%;
		}

		#head {
			height: 100px;
			margin: 0 0 0 0 !important;
			padding: 1px 50px 40px;
		}

		#head h1 {
			font-family: 'Raleway', sans-serif;
			font-size: 50px;
			font-weight: 100;
		}

		#galerie {
			margin: 0 0 0 0 !important;
			padding: 0 0 0 0 !important;
			display: block;
			width: 100%;
		}

		.photo {
			float:left;
			display: inline-block;
			background-size: auto 100% !important;
			font-size: 0px;
			overflow: hidden;
		}

		.photo span {
			margin: 0 0 0 0 !important;
			padding: 0 0 0 0 !important;
			font-size: 0px;
			display: block;
			width: 500px;
			height: 500px;
		}

		.photo span:hover {
			background: rgba(0,0,0,0.2);
			font-size: 30px !important;
			padding: 130px 0 0 0 !important;
			color: #FFFFFF;
			text-align: center;
		}

		#photoblock {
			float:left;
			display: inline-block;
			width: 900px;
			height: 900px;
			cursor: pointer;
		}

		* {
			-webkit-touch-callout: none;
			-webkit-user-select: none;
			-khtml-user-select: none;
			-moz-user-select: none;
			-ms-user-select: none;
			user-select: none;
		}
	</style>
	<script src="http://code.jquery.com/jquery-latest.min.js"></script>
	<script type="text/javascript">
		$( document ).ready(function() {
			var width = $(document).width() / 4;
			var phblock = document.getElementsByClassName("photo");
			for(var i = 0; i < phblock.length; i++) {
				phblock[i].style.width = width;
				phblock[i].style.height = width;
			}
		});
	</script>
</head>
<body>
	<div id="head">
		<h1><b>Ray</b>Tracer<a href="/" style="float:right;color:black;text-decoration:none;">Last gallery</a></h1>
	</div>
	<div id="galerie">
    	<?php
    		$i = 0;
			$directory =  "./";
			$images = glob($directory . "*");
			foreach($images as $img) {
				if (strcmp($img, "./index.php") != 0) {
					$imgname = explode("-", $img)[1];
					$imgname = substr($imgname, 4, -4);
					if ($imgname == "1") { $i++; }
					echo '<div id="photoblock" class="photo" style="background: url(' . $img . ') no-repeat center center;"><span id="intoblock">Scene ' . $i . '<br>Eye ' . $imgname . '</span></div>';
				}
			}

		?>
	</div>
</body>
</html>