<html>
<head>
	<title>RayTracer || Galeries</title>
	<link href='http://fonts.googleapis.com/css?family=Raleway:100,200,300,400' rel='stylesheet' type='text/css'>
	<style type="text/css">
		body {
			margin: 0 0 0 0 !important;
			padding: 0 0 0 0 !important;
			overflow: hidden;
			max-width: 100%;
			max-height: 100%;
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

		.arrow {
			font-family: 'Raleway', sans-serif;
			font-size: 50px;
			position: absolute;
			top: 35px;
			font-weight: 100;
		}

		.arrow-right {
			right: 350px;
			cursor: pointer;
		}

		.arrow-left {
			right: 380px;
			cursor: pointer;
		}

		#slides {
			display:none;
		}

		.no-select {
			-webkit-touch-callout: none;
			-webkit-user-select: none;
			-khtml-user-select: none;
			-moz-user-select: none;
			-ms-user-select: none;
			user-select: none;
		}
	</style>
	<script src="http://code.jquery.com/jquery-latest.min.js"></script>
	<script src="jquery.slides.min.js"></script>

	<script>
	$(function(){
		$("#slides").slidesjs({
			width: 940,
			height: $(document).height() - 200,
			pagination: false,
			navigation: {
				effect: "fade"
			},
			effect: {
				fade: {
					speed: 400
				}
        	}
		});
	});
	$(document).keydown(function(e){
			 if(e.keyCode == 37) { $('a.slidesjs-previous').click(); }
		else if(e.keyCode == 39) { $('a.slidesjs-next').click(); }
	});
	</script>
</head>
<body>
	<div id="head">
		<h1><b>Ray</b>Tracer<a href="/old" style="float:right;color:black;text-decoration:none;">Old gallery</a></h1>
	</div>
	<div id="slides">
    	<?php

			$directory =  "img/";
			$images = glob($directory . "*");
			foreach($images as $img) {
				$imgname = substr($img, 4, -4);
				echo '<img src="' . $img . '" alt="">';
			}

		?>
	<span href="#" class="arrow arrow-left no-select slidesjs-previous slidesjs-navigation"><</span>
	<span href="#" class="arrow arrow-right no-select slidesjs-next slidesjs-navigation">></span>
	</div>
</body>
</html>