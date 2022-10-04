function msToTime(s) {
  s = (s - s % 1000) / 1000;
  const secs = s % 60;
  s = (s - secs) / 60;
  const mins = s % 60;
  const hrs = (s - mins) / 60;

  return hrs + ':' + mins + ':' + secs;
}

function count() {
  let t = new Date();
  const temp = new Date(t.getFullYear(), t.getMonth(), t.getDate(), 16, 20);

  // the following is to handle cases where the times are on the opposite side of
  // midnight e.g. when you want to get the difference between 9:00 PM and 5:00 AM
  //if (t < temp)
  //  t.setDate(t.getDate() + 1);

  t -= temp;

  let s;
  if (t > 0)
    s = "since";
  else {
    t = Math.abs(t);
    s = "until";
  }

  console.log(`${msToTime(t)} ${s} 4:20 PM`);

  setTimeout(count, 1000); // Repeat every second
};

count();
