function to12Hour(s) {
  let t = 'PM';
  s = s.split(':');

  if (s[0] < 12)
    t= 'AM';
  else if (s[0] > 12)
    s[0] = String(Number(s[0]) - 12).padStart(2, '0');

  return s.join(':') + t;
}

function to24Hour(s) {
  const t = s.slice(-2);
  s = s.slice(0, -2).split(':');

  if (t === 'PM' && s[0] < 12)
    s[0] = Number(s[0]) + 12;
  else if (t === 'AM' && s[0] >= 12)
    s[0] = String(Number(s[0]) - 12).padStart(2, '0');
  
  return s.join(':');
}

if (require.main === module) {
  let res;
  switch (process.argv[2]) {
    case '12': res = to12Hour(process.argv[3]); break;
    case '24': res = to24Hour(process.argv[3]); break;
    default: res = "Wrong number of arguments";
  }

  console.log(res);
}

module.exports = {
  to12Hour: to12Hour,
  to24Hour: to24Hour
};
