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
        setupHisTotalMoney()
    }
    
    func setupHisTotalMoney() {
        var totalMoney: Double = 0.0
        var totalAcoesMoney: Double = 0.0
        var totalFiiMoney: Double = 0.0
        var totalCriptoMoney: Double = 0.0
        var entries = [ChartDataEntry]()

        let ref = Database.database().reference()
        let uid = Auth.auth().currentUser?.uid
        
        ref.child("users").child(uid!).child("assets").child("totalCarteira").observe(.value) { data in
            totalMoney = data.value as! Double
            self.setupCentralText(total: totalMoney)
        }
        
        ref.child("users").child(uid!).child("assets").child("acoes").child("inTotal").observe(.value) { data in
            totalAcoesMoney = data.value as! Double
            entries.append(ChartDataEntry(x: totalAcoesMoney, y: totalAcoesMoney))
            self.setupChart(entries: entries)
        }
        
        ref.child("users").child(uid!).child("assets").child("fii").child("inTotal").observe(.value) { data in
            totalFiiMoney = data.value as! Double
            entries.append(ChartDataEntry(x: totalFiiMoney, y: totalFiiMoney))
            self.setupChart(entries: entries)
        }
        
        ref.child("users").child(uid!).child("assets").child("cripto").child("inTotal").observe(.value) { data in
            totalCriptoMoney = data.value as! Double
            entries.append(ChartDataEntry(x: totalCriptoMoney, y: totalCriptoMoney))
            self.setupChart(entries: entries)
        }
    }
    
    func setupChart(entries: [ChartDataEntry]) {
        pieChart.frame = CGRect(x: 0, y: 0, width: 300, height: 300)
        pieChart.center = self.center
        self.addSubview(pieChart)
        
        let set = PieChartDataSet(entries: entries)
        set.valueFont = UIFont(name: "Poppins-SemiBold", size: 12)!
        set.colors = ChartColorTemplates.pastel()
        let data = PieChartData(dataSet: set)
        pieChart.data = data
        
        
        pieChart.legend.enabled = false
        pieChart.rotationEnabled = false
        
        pieChart.transparentCircleColor = UIColor(red: 1.0, green: 1.0, blue: 1.0, alpha: 0.0)
    }
    
    func setupCentralText(total: Double) {
        let myMoney = String(total)
        
        let attributes = [ NSAttributedString.Key.foregroundColor: UIColor.black,
                           NSAttributedString.Key.font: UIFont(name: "Poppins-ExtraBold", size: 15)]
        let myAttrString = NSAttributedString(string: "R$ \(myMoney)", attributes: attributes as [NSAttributedString.Key : Any])
        pieChart.centerAttributedText = myAttrString
        pieChart.drawCenterTextEnabled = true
    }
}
