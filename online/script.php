<?php
  $ftp_server = "ftp.jean-barriere.fr";
  $user = "jean-barriere.fr";
  $pass = "i57Zc15Fm9";
  $path = "/raytracer/img";
  $pathlist = "/raytracer";
  $list = "../list.txt";
  $link = "http://raytracer.jean-barriere.fr/img/";
  $out = ".tmp_list.txt";

  $id = ftp_connect($ftp_server, "21") or die("Impossible de se connecter au serveur $ftp_server");
  if (ftp_login($id, $user, $pass))
    {
      ftp_pasv($id, true);
      $filelist = ftp_nlist($id, $path);
      foreach($filelist as $file) {
        if (strcmp($file, ".") != 0 && strcmp($file, "..") != 0)
          ftp_delete($id, $path . "/" . $file);
      }
      ftp_rmdir($id, $path);
      ftp_mkdir($id, $path);
      ftp_chdir($id, $path);
      $fd = fopen('list.txt', 'r');
      $fdout = fopen($out, 'w');
      while (!feof($fd)) {
        $file = trim(fgets($fd));
	if (isset($file) && strlen($file) != 0) {
	  if (ftp_put($id, $file, $file, FTP_BINARY)) {
            echo "$file uploaded with success\n";
          } else {
            echo "Error during the upload of : $file\n";
          }
	  fwrite($fdout, $link . $file . "\n");
	}
      }
      fclose($fd);
      ftp_chdir($id, $pathlist);
      if (ftp_put($id, "list.txt", $out, FTP_BINARY)) {
        echo "list.txt uploaded with success\n";
      } else {
        echo "Error during the upload of : list.txt\n";
      }
      unlink($out);
    }
  ftp_close($id);
?>