const arr = [
  '00:01:00AM',
  '01:01:00AM',
  '02:01:00AM',
  '03:01:00AM',
  '04:01:00AM',
  '05:01:00AM',
  '06:01:00AM',
  '07:01:00AM',
  '08:01:00AM',
  '09:01:00AM',
  '10:01:00AM',
  '11:01:00AM',
  '12:01:00PM',
  '01:01:00PM',
  '02:01:00PM',
  '03:01:00PM',
  '04:01:00PM',
  '05:01:00PM',
  '06:01:00PM',
  '07:01:00PM',
  '08:01:00PM',
  '09:01:00PM',
  '10:01:00PM',
  '11:01:00PM',
  '12:01:00AM'
];

function timeConversion(s) {
    const t = s.slice(-2);
    s = s.slice(0, -2).split(':');

    if (t === 'PM' && s[0] < 12)
      s[0] = Number(s[0]) + 12;
    else if (t === 'AM' && s[0] >= 12)
      s[0] = String(Number(s[0]) - 12).padStart(2, '0');
    
    return s.join(':');
}

arr.forEach((s) => console.log(timeConversion(s)));
