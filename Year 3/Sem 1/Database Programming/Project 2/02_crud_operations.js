// ==========================
// INSERT OPERATIONS
// ==========================

// Insert one attendee
db.attendees.insertOne({
    name: "Nur Aisyah",
    email: "aisyah@graduate.utm.my",
    type: "Student",
    registered_events: [
      ObjectId("695cc07afc9b8ea1d1024a15")
    ],
    interests: ["Cloud", "DevOps"]
  })

// Insert multiple events
db.Events.insertMany([
    {
      title: "AI Bootcamp 2026",
      category: "Techlonogy",
      date: ISODate("2026-06-01T09:00:00Z"),
      venue_id: ObjectId("6598ef01c2b5a12345678901"),
      organizer_id: ObjectId("6598f122c2b5a12345678913"),
      description: "Join us, to learn more on AI in future!",

      schedule: [
        {time: "08:30 AM", activity: "Regitration" },
        {time: "10.00 AM", activity: "Keynote: How AI changes future ?"},
        {time: "11.00 AM", activity: "Hands on session" },
        {time: "12.30 PM", activity: "Lunch Time" },
        {time: "2.00 PM", activity: "Photo session and Goodbye !"}
      ],

      tickets: [
        {type: "Student", price: 10, available_seats: 100},
        {type: "Non-Student", price: 25, available_seats: 100}
      ],
      tags: ["AI","ML","Workshop"]
    },
    {
      title: "Fintech Innovation Forum",
      category: "Finance",
      date: ISODate("2026-08-15T10:00:00Z"),
      venue_id: ObjectId("6598ef01c2b5a12345678902"),
      organizer_id: ObjectId("6598f122c2b5a12345678914"),
      description: "A high-level summit focusing on blockchain, digital banking, and the future of financial technology.",

    schedule: [
      { time: "08:30 AM", activity: "Registration & Coffee" },
      { time: "10:00 AM", activity: "Keynote: Central Bank Digital Currencies" },
      { time: "01:30 PM", activity: "Panel: Cybersecurity in Open Banking" },
      { time: "04:00 PM", activity: "Startup Pitch Competition" }
    ],

    tickets: [
      { type: "Early Access", price: 500, available_seats: 50 },
      { type: "Corporate Pass", price: 1200, available_seats: 200 },
      { type: "Exhibitor Pass", price: 3500, available_seats: 20 }
    ],
      tags: ["Blockchain","Finance"]
    }
  ]);
  

// ==========================
// QUERY OPERATIONS
// ==========================

// Find attendees with type "General"
db.Attendees.find({type: "General"})

// Find one attendee with type "General"
db.Attendees.findOne({type: "General"})

// Find organizers named "UTM Faculty of Computing" using $eq
db.Organisers.find({ org_name: { $eq: "UTM Faculty of Computing"}})

// Find venues with capacity greater than 2000 using $gt
db.Venues.find({ capacity: { $gt: 2000 } })

// Find events scheduled before July 1, 2026 using $lt
db.Events.find({ date: { $lt: ISODate("2026-07-01T00:00:00Z") } })

// Find events with the tag "Blockchain" using $in
db.Events.find({ tags: { $in: ["Blockchain"] } })

// Find events in the "Technology" category and happening after January 1, 2026 using $and
db.Events.find({
    $and: [
      { category: "Technology" },
      { date: { $gt: ISODate("2026-01-01T00:00:00Z") } }
    ]
  })

// Find attendees who are either "Student" or "Academic" using $or
db.Attendees.find({
    $or: [
      { type: "Student" },
      { type: "Academic" }
    ]
  })

// Find venues that offer "High-speed WiFi"
db.Venues.find({ facilities: "High-speed WiFi" })

// Project only the name and email of all attendees
db.Attendees.find(
    {},
    { name: 1, email: 1, _id: 0 }
  )

// Update One Attendee to set type to "Professional"
db.Attendees.updateOne(
  { email: "siti.a@utm.edu.my" },
  { $set: { type: "Professional" } }
)

// Update Many Organisers to set verified_status to true
db.Organisers.updateMany(
  { verified_status: false },
  { $set: { verified_status: true } }
);

// Use $set to update the category of "AI Bootcamp 2026" event to "Education"
db.Events.updateOne(
  { title: "AI Bootcamp 2026" },
  { $set: { category: "Education" } }
)

// Use $inc to increase the rating of "SEA Finance Hub" organiser by 0.2
db.Organisers.updateOne(
  { org_name: "SEA Finance Hub" },
  { $inc: { rating: 0.2 } }
)

// Use $push to add "Startups" to the interests array of attendee "Kevin Wong"
db.Attendees.updateOne(
  { name: "Kevin Wong" },
  { $push: { interests: "Startups" } }
)

// Use $pull to remove "Blockchain" from the interests array of attendee "Kevin Wong"
db.Attendees.updateOne(
  { name: "Kevin Wong" },
  { $pull: { interests: "Blockchain" } }
)

// Delete one attendee with email
db.Attendees.deleteOne({ email: "siti.a@utm.edu.my" })

// Delete many events in the "Finance" category
db.Events.deleteMany({ category: "Finance" })