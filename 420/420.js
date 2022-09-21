function msToTime(s) {
  var ms = s % 1000;
  s = (s - ms) / 1000;
  var secs = s % 60;
  s = (s - secs) / 60;
  var mins = s % 60;
  var hrs = (s - mins) / 60;

  return hrs + ':' + mins + ':' + secs;
}

function count() {
  let t = new Date();
  const temp = new Date(t.getFullYear(), t.getMonth(), t.getDay(), 4, 20);

  console.log(new Date(t - temp));
  t -= temp;

  let s;
  if (t < 0) {
    t = Math.abs(t);
    s = "since";
  } else
    s = "until";

  //console.log(`${msToTime(t)} ${s} 4:20`);

  setTimeout(count, 60000); // Repeat every minute
};

//count();


// use a constant date (e.g. 2000-01-01) and the desired time to initialize two dates

var date1 = new Date(2000, 0, 1,  9, 0); // 9:00 AM
var date2 = new Date(2000, 0, 1, 17, 0); // 5:00 PM

// the following is to handle cases where the times are on the opposite side of
// midnight e.g. when you want to get the difference between 9:00 PM and 5:00 AM

if (date2 < date1) {
    date2.setDate(date2.getDate() + 1);
}

var diff = date2 - date1;

// 28800000 milliseconds (8 hours)

console.log(msToTime(diff));