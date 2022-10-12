//
//  ChartTableViewCell.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 20/09/22.
//

import Charts
import UIKit
import FirebaseDatabase
import FirebaseAuth

class ChartTableViewCell: UITableViewCell, ChartViewDelegate {
    
    var pieChart = PieChartView()

    @IBOutlet weak var investidoLabel: UILabel!
    @IBOutlet weak var chartBackground: UIView!
    @IBOutlet weak var percentButton: UIButton!
    @IBOutlet weak var posicaoAtualLabel: UILabel!
    @IBOutlet weak var rendimentoLabel: UILabel!
    
    var hisTotalMoney = 0
        
    @IBAction func showPercent(_ sender: Any) {
        var keyToPercent: Bool
        keyToPercent = pieChart.isUsePercentValuesEnabled == true ? true : false
        pieChart.usePercentValuesEnabled = !keyToPercent
    }
    
    func setupView() {
        chartBackground.layer.cornerRadius = 20
        chartBackground.layer.shadowColor = UIColor.black.cgColor
        chartBackground.layer.shadowOffset = CGSize(width: 0.0, height: 2.0)
        chartBackground.layer.shadowRadius = 4.0
        chartBackground.layer.shadowOpacity = 0.5
        chartBackground.layer.masksToBounds = false
        
        percentButton.layer.cornerRadius = 5
        pieChart.delegate = self
        setupChart()
        setupHisTotalMoney()
    }
    
    func setupHisTotalMoney() {
        let ref = Database.database().reference()
        let uid = Auth.auth().currentUser?.uid
        
//        ref.child("users").child(uid!).child("assets").observe(.value) { snapshot in
//            for child in snapshot.children {
//                //print(child)
//            }
//        }
    }
    
    func setupChart() {
        pieChart.frame = CGRect(x: 0, y: 0, width: 300, height: 300)
        pieChart.center = self.center
        self.addSubview(pieChart)
        
        var entries = [ChartDataEntry]()
        
        for x in 0..<10 {
            entries.append(ChartDataEntry(x: Double(x), y: Double(x)))
        }
        
        let set = PieChartDataSet(entries: entries)
        set.colors = ChartColorTemplates.colorful()
        let data = PieChartData(dataSet: set)
        pieChart.data = data
        
        let myMoney = "33.000,00"
        
        let attributes = [ NSAttributedString.Key.foregroundColor: UIColor.black,
                           NSAttributedString.Key.font: UIFont(name: "Poppins-ExtraBold", size: 15)]
        let myAttrString = NSAttributedString(string: myMoney, attributes: attributes as [NSAttributedString.Key : Any])
        pieChart.centerAttributedText = myAttrString
        pieChart.drawCenterTextEnabled = true
        pieChart.legend.enabled = false
        pieChart.rotationEnabled = false
        
        pieChart.transparentCircleColor = UIColor(red: 1.0, green: 1.0, blue: 1.0, alpha: 0.0)
        
        
    }
}
